/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:44:34 by niclopez          #+#    #+#             */
/*   Updated: 2024/07/04 21:33:14 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(int fd, t_game *game)
{
	char	*line;
	int		i;
	
	game->num_filas = 0;
	game->num_columnas = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s", line);
		i = 0;
		while (line[i] != '\0')
		{
			game->map[game->num_filas][i] = line[i];
			if (line[i] == 'P')
			{
				game->start.x = i;
				game->start.y = game->num_filas;
			}
			if (line[i] == 'E')
			{
				game->end.x = i;
				game->end.y = game->num_filas;
			}
			i++;
		}
		free(line);
		game->num_filas++;
		if (i > game->num_columnas)
			game->num_columnas = i - 1;
	}

	ft_printf(" %dx%d\n", game->num_filas, game->num_columnas);
	ft_printf("P: (%d, %d)\n", game->start.x, game->start.y);
	ft_printf("E: (%d, %d)\n", game->end.x, game->end.y);
	
	if (!map_validator(game))
	{
		ft_printf("MAPA NO VALIDO!\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("El mapa es valido. OK!\n");
}

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	return (fd);
}