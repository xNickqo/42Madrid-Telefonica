/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_valid_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:20:30 by niclopez          #+#    #+#             */
/*   Updated: 2024/08/14 19:51:47 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	print_visited(t_game *game, bool visited[MX_ROWS][MX_COLS])
{
    int i, j;
    for (i = 0; i < game->rows; i++)
    {
        for (j = 0; j < game->cols; j++)
        {
            ft_printf("%d ", visited[i][j]);
        }
        ft_printf("\n");
    }
}*/

/*
----------------------------------------------------------------------
			Inicializa el array "visited" en FALSE
----------------------------------------------------------------------
*/

void	init_visited(t_game *game, bool visited[MX_ROWS][MX_COLS])
{
	int		i;
	int		j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			visited[i][j] = false;
			j++;
		}
		i++;
	}
}

/*
---------------------------------------------------------------------
	Verifica que todas las posiciones C y E hayan sido visitadas

	Si C o E no han sido visitadas devolvera FALSE, sino TRUE
---------------------------------------------------------------------
*/

bool	check_visited(t_game *game, bool visited[MX_ROWS][MX_COLS])
{
	int		i;
	int		j;
	
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E')
				&& !visited[i][j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/*
---------------------------------------------------------------------------
	Se encarga de llamar a dfs y verificar si el camino es valido 
---------------------------------------------------------------------------
*/

bool	is_valid_path(t_game *game)
{
	bool	visited[MX_ROWS][MX_COLS];
	
	init_visited(game, visited);
	dfs(game, game->start.x, game->start.y, visited);
	return (check_visited(game, visited));
}
/* 	if (all_visited)
		ft_printf("Todas las celdas 'C' y 'E' han sido visitadas\n");
	else
		ft_printf("No todas las celdas 'C' y 'E' han sido visitadas\n"); 
    ft_printf("Matriz visited:\n");
    print_visited(visited, game->rows, game->cols); */