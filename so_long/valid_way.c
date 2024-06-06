/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:20:30 by niclopez          #+#    #+#             */
/*   Updated: 2024/06/06 22:18:37 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void print_visited(bool visited[MAX_FILAS][MAX_COLUMNAS], int num_filas, int num_columnas)
{
    int i, j;
    for (i = 0; i < num_filas; i++)
    {
        for (j = 0; j < num_columnas; j++)
        {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
} */

bool	is_valid_pos(t_game *game, int x, int y, bool visited[MAX_FILAS][MAX_COLUMNAS])
{
	return x >= 0 && x < game->num_columnas && y >= 0 && y < game->num_filas && 
		game->map[y][x] != '1' && !visited[y][x];
}

bool	dfs(t_game *game, int x, int y, bool visited[MAX_FILAS][MAX_COLUMNAS], int *obj)
{
	int		i;
	int		new_x;
	int		new_y;
	//printf("Estas en: (%d, %d)\n", x, y);
	visited[y][x] = true;
	if (game->map[y][x] == 'C')
	{
		//printf("Coleccionable encontrado en: (%d, %d)\n", x, y);
		(*obj)--;
	}
	if (game->map[y][x] == 'E')
	{
		if(*obj == 0)
		{
			//printf("Encontraste la salida CON TODOS los coleccionables en : (%d, %d)\n", x, y);
			return (true);
		}
		//printf("Encontraste la salida pero SIN los coleccionables en: (%d, %d)\n", x, y);
	}
	t_pos moves[4] = {{0, 1}, {1, 0},{0, -1}, {-1, 0}};
	i = 0;
	while (i < 4)
	{
		new_x = x + moves[i].x;
		new_y = y + moves[i].y;
		if (is_valid_pos(game, new_x, new_y, visited))
		{
			if (dfs(game, new_x, new_y, visited, obj))
				return (true);
		}
		i++;
	}
	//printf("Retrocediendo desde (%d, %d)\n", x, y);
	return (false);
}

bool	is_valid_path(t_game *game)
{
	bool	visited[MAX_FILAS][MAX_COLUMNAS] = {false};
	bool	all_visited;
	int		i;
	int		j;
	int		obj;

	obj = game->obj_count;
	dfs(game, game->start.x, game->start.y, visited, &obj);

	//Verificar si todas las celdas 'C' y 'E' han sido visitadas
	all_visited = true;
	i = 0;
	while (i < game->num_filas)
	{
		j = 0;
		while (j < game->num_columnas)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E') && !visited[i][j])
			{
				all_visited = false;
				break;
			}
			j++;
		}
		if (!all_visited)
			break;
		i++;
	}
	if (all_visited)
		printf("Todas las celdas 'C' y 'E' han sido visitadas por el jugador.\n");
	else
		printf("No todas las celdas 'C' y 'E' han sido visitadas por el jugador.\n");
    //printf("Matriz visited:\n");
    //print_visited(visited, game->num_filas, game->num_columnas);
	return (all_visited);
}


