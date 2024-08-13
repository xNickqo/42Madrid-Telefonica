/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:35:49 by niclopez          #+#    #+#             */
/*   Updated: 2024/08/13 19:21:37 by niclopez         ###   ########.fr       */
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
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
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
	while (i < game->rows)
	{
		if (game->map[i][0] != '1'
			|| game->map[i][game->cols - 1] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < game->cols)
	{
		if (game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	is_rectangular(t_game *game)
{
	if (game->rows == game->cols)
		return (false);
	return (true);
}

bool	map_validator(t_game *game)
{
	if (!check_walls(game))
	{
		ft_printf("Error: el mapa no esta rodeado por muros\n");
		return (false);
	}
	if (has_duplicates(game))
	{
		ft_printf("Error: hay elementos duplicados o inexistentes\n");
		return (false);
	}
	if (!is_valid_path(game))
	{
		ft_printf("Error: el camino no es valido\n");
		return (false);
	}
	if (!is_rectangular(game))
	{
		ft_printf("Error: el mapa es cuadrado\n");
		return (false);
	}
	return (true);
}
