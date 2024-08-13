/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:44:34 by niclopez          #+#    #+#             */
/*   Updated: 2024/08/13 19:22:39 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_game_info(t_game *game)
{
	ft_printf(" %dx%d\n", game->rows, game->cols);
	ft_printf("P: (%d, %d)\n", game->start.x, game->start.y);
	ft_printf("E: (%d, %d)\n", game->end.x, game->end.y);
}

void	process_line(t_game *game, char *line)
{
	int	i;

	ft_printf("%s", line);
	i = 0;
	while (line[i] != '\0')
	{
		game->map[game->rows][i] = line[i];
		if (line[i] == 'P')
		{
			game->start.x = i;
			game->start.y = game->rows;
		}
		if (line[i] == 'E')
		{
			game->end.x = i;
			game->end.y = game->rows;
		}
		(i)++;
	}
	free(line);
	game->rows++;
	if (i > game->cols)
		game->cols = i - 1;
}

void	read_file(int fd, t_game *game)
{
	char	*line;

	game->rows = 0;
	game->cols = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		process_line(game, line);
	}
	print_game_info(game);
}
