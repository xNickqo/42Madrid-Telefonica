/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:20:30 by niclopez          #+#    #+#             */
/*   Updated: 2024/06/02 19:42:57 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid_pos(t_game *game, int x, int y, bool visited[MAX_FILAS][MAX_COLUMNAS])
{
    return x >= 0 && x < game->num_columnas && y >= 0 && y < game->num_filas &&
           game->map[y][x] != '1' && !visited[y][x];
}

bool dfs(t_game *game, int x, int y, bool visited[MAX_FILAS][MAX_COLUMNAS], int *obj)
{
	int		i;
	int		new_x;
	int		new_y;

	printf("Explorando posición (%d, %d)\n", x, y);

    if (game->map[y][x] == 'C')
	{
        printf("Coleccionable encontrado en: (%d, %d)\n", x, y);
        (*obj)--;
		/* game->map[y][x] = '0'; */
		visited[y][x] = true;
    }
    visited[y][x] = true;

	t_pos moves[4] = {{0, 1}, {1, 0},{0, -1}, {-1, 0}};
    i = 0;
    while (i < 4) {
        new_x = x + moves[i].x;
        new_y = y + moves[i].y;
        if (is_valid_pos(game, new_x, new_y, visited))
		{
            printf("Moviendo a: (%d, %d)\n", new_x, new_y);
            if (dfs(game, new_x, new_y, visited, obj))
                return (true);
        }
        i++;
    }

    if (game->map[y][x] == 'E' && *obj == 0)
	{
        printf("Encontre la salida con todos los coleccionables recojidos en: (%d, %d)\n", x, y);
        return (true);
    }
	
    visited[y][x] = false;
	printf("Retrocediendo desde (%d, %d)\n", x, y);
    return (false);
}

bool is_valid_path(t_game *game)
{
    bool visited[MAX_FILAS][MAX_COLUMNAS] = {false};
    int obj;
    int i;
    int j;

	obj = 0;
	i = 0;
    while (i < game->num_filas)
	{
        j = 0;
        while (j < game->num_columnas)
		{
            if (game->map[i][j] == 'C')
                obj++;
            j++;
        }
        i++;
    }
	printf("Total de coleccionables: %d\n", obj);
    return (dfs(game, game->start.x, game->start.y, visited, &obj));
}
