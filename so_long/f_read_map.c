/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_read_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 02:35:29 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/03 20:10:27 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_game_info(t_game *game)
{
	ft_printf(" %dx%d\n", game->rows, game->cols);
	ft_printf("P: (%d, %d)\n", game->start.x, game->start.y);
	ft_printf("E: (%d, %d)\n", game->end.x, game->end.y);
}

/*
------------------------------------------------------------------------------
		Se encarga de introducir el mapa en el array linea por linea
		y localizar tanto el punto de inicio como la salida.
------------------------------------------------------------------------------
*/

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
	game->start.x = -1;
	game->start.y = -1;
	game->end.x = -1;
	game->end.y = -1;
	game->start_count = 0;
	game->exit_count = 0;
	game->obj_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		process_line(game, line);
	}
	print_game_info(game);
}

/*
------------------------------------------------------------------------------
						Lectura y validacion del mapa
------------------------------------------------------------------------------
*/

void	read_map(char *filename, t_game *game)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	read_file(fd, game);
	if (!map_validator(game))
	{
		ft_printf("MAPA NO VALIDO!\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	ft_printf("El mapa es valido. OK!\n");
}
