/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 02:35:29 by niclopez          #+#    #+#             */
/*   Updated: 2024/06/05 18:23:41 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_counts(int start_count, int exit_count, int obj_count)
{
	if (start_count > 1)
		return (true);
	if (exit_count > 1)
		return (true);
	if (start_count == 0 || exit_count == 0 || obj_count == 0)
		return (true);
	return (false);
}

bool	has_duplicates(t_game *game)
{
	int	start_count;
	int	exit_count;
	int	i;
	int	j;
	
	start_count = 0;
	exit_count = 0;
	game->obj_count = 0;
	i = 0;
	while (i < game->num_filas)
	{
		j = 0;
		while (j < game->num_columnas)
		{
			if (game->map[i][j] == 'P')
				start_count++;
			else if (game->map[i][j] == 'E')
				exit_count++;
			else if (game->map[i][j] == 'C')
				game->obj_count++;
			j++;
		}
		i++;
	}
	return (check_counts(start_count, exit_count, game->obj_count));
}

bool	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->num_filas)
	{
		if (game->map[i][0] != '1' || game->map[i][game->num_columnas - 1] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < game->num_columnas)
	{
		if (game->map[0][i] != '1' || game->map[game->num_filas - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	is_rectangular(t_game *game)
{
	if (game->num_filas == game->num_columnas)
		return (false);
	return (true);
}

bool	map_validator(t_game *game)
{
	if (!check_walls(game))
	{
		printf("Error: el mapa no esta rodeado por muros\n");
		return (false);
	}
	if (has_duplicates(game))
	{
		printf("Error: hay elementos duplicados o inexistentes\n");
		return (false);
	}
	if (!is_valid_path(game))
	{
		printf("Error: el camino no es valido\n");	
		return (false);
	}
	if (!is_rectangular(game))
	{
		printf("Error: el mapa es cuadrado\n");
		return(false);
	}
	return (true);
}

void read_map(char *filename, t_game *game)
{
	int		fd;

	fd = open_file(filename);
	read_file(fd, game);
	close(fd);
}