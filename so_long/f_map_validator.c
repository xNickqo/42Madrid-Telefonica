/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_map_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:35:49 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/03 20:07:26 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_counts(int start_count, int exit_count, int obj_count)
{
	if (start_count > 1)
	{
		ft_printf("Error: Hay elementos duplicados\n");
		return (true);
	}
	if (exit_count > 1)
	{
		ft_printf("Error: Hay elementos duplicados\n");
		return (true);
	}
	if (start_count == 0 || exit_count == 0 || obj_count == 0)
	{
		ft_printf("Error: Faltan elementos\n");
		return (true);
	}
	return (false);
}

bool	has_duplicates(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'P')
				game->start_count++;
			else if (game->map[i][j] == 'E')
				game->exit_count++;
			else if (game->map[i][j] == 'C')
				game->obj_count++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
			{
				ft_printf("Error: El mapa contiene caracteres no permitidos\n");
				return (true);
			}
			j++;
		}
		i++;
	}
	return (check_counts(game->exit_count, game->exit_count, game->obj_count));
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

/*
------------------------------------------------------------------------------
				Funcion que se encarga de verificar que:
					-El mapa esté rodeado por muros
					-Exixtan elementos duplicados o inexistentes
					-El jugador tenga un camino valido
					-El mapa sea rectangular
------------------------------------------------------------------------------
*/

bool	map_validator(t_game *game)
{
	if (!check_walls(game))
	{
		if (game->cols > MX_COLS || game->rows > MX_ROWS)
			ft_printf("Error: El mapa supera las maximas dimensiones\n");
		else
			ft_printf("Error: El mapa no esta rodeado por muros\n");
		return (false);
	}
	if (has_duplicates(game))
		return (false);
	if (!is_valid_path(game))
	{
		ft_printf("Error: El camino no es valido\n");
		return (false);
	}
	if (!is_rectangular(game))
	{
		ft_printf("Error: El mapa es cuadrado\n");
		return (false);
	}
	return (true);
}
