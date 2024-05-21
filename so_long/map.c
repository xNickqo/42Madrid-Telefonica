/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:44:34 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/21 19:01:40 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

bool	has_duplicates(t_game *game)
{
	int	start_count;
	int	exit_count;
	int	obj_count;
	int	i;
	int	j;
	
	start_count = 0;
	exit_count = 0;
	obj_count = 0;
	i = 0;
	while (i < game->num_filas)
	{
		j = 0;
		while (j < game->num_columnas)
		{
			if (game->map[i][j] == 'P')
			{
				if (start_count > 0)
				{
					printf("Error: P Duplicada");
					return (true);
				}
				start_count++;
			}
			else if (game->map[i][j] == 'E')
			{
				if (exit_count > 0)
				{
					printf("Error: E Duplicada");
					return (true);
				}
				exit_count++;
			}
			else if (game->map[i][j] == 'C')
				obj_count++;
			j++;
		}
		i++;
	}
	if (start_count == 0 || exit_count == 0 || obj_count == 0)
	{
		printf("Error: No hay punto de inicio (P), salida (E) u objetos (C) en el mapa\n");
		return (true);
	}
	return (false);
}

bool	map_validator(t_game *game)
{
	int	i;
	//Verificamos si el mapa esta rodeado por muros
	printf(" %dx%d\n", game->num_filas, game->num_columnas);
	i = 0;
	while (i < game->num_filas)
	{
		if (game->map[i][0] != '1' || game->map[i][game->num_columnas - 1] != '1')
		{
			printf("Error: El mapa no está rodeado por muros en la primera y ultima filas\n");
			return (false);
		}
		i++;
	}
	i = 0;
	while (i < game->num_columnas)
	{
		if (game->map[0][i] != '1' || game->map[game->num_filas - 1][i] != '1')
		{
			printf("Error: El mapa no está rodeado por muros en la primera y ultima columnas\n");
			return (false);
		}
		i++;
	}
	//Verificar duplicados
	if (has_duplicates(&game))
		return (false);
	return (true);
}

void read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
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
	close(fd);
	if (!map_validator(&game))
	{
		printf("Error: El mapa no es valido\n");
		exit(EXIT_FAILURE);
	}
	printf("El mapa es valido. OK!\n");
}

/* int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Debes usar un solo argumento tal que: %s <archivo>.ber\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    map(argv[1]);
    return 0;
} */