/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:20:30 by niclopez          #+#    #+#             */
/*   Updated: 2024/08/13 19:26:21 by niclopez         ###   ########.fr       */
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
-------------------------------------------------------------------------------
	Se encarga de llamar a dfs y verificar si todas las celdas 'C' y 'E' 
	han sido visitadas 
-------------------------------------------------------------------------------
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

bool	check_visited(t_game *game, bool visited[MX_ROWS][MX_COLS])
{
	int		i;
	int		j;
	bool	all_visited;

	all_visited = true;
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E')
				&& !visited[i][j])
			{
				all_visited = false;
				break ;
			}
			j++;
		}
		if (!all_visited)
			break ;
		i++;
	}
	return (true);
}

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