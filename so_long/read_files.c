/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:44:34 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/29 20:05:24 by niclopez         ###   ########.fr       */
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
		printf("%s", line);
		i = 0;
		while (line[i] != '\0')
		{
			if (game->num_columnas >= MAX_COLUMNAS)
			{
				printf("Error: linea demasiado larga");
				exit(EXIT_FAILURE);
			}
			game->map[game->num_filas][i] = line[i];
			i++;
		}
		free(line);
		game->num_filas++;
		if (i > game->num_columnas)
			game->num_columnas = i - 1;
	}
	printf(" %dx%d\n", game->num_filas, game->num_columnas);
	if (!map_validator(game))
	{
		printf("Error: El mapa no es valido\n");
		exit(EXIT_FAILURE);
	}
	printf("El mapa es valido. OK!\n");
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