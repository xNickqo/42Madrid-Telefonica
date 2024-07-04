/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:20:30 by niclopez          #+#    #+#             */
/*   Updated: 2024/07/04 23:04:39 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void print_visited(bool visited[MAX_FILAS][MAX_COLUMNAS], int num_filas, 
	int num_columnas)
{
    int i, j;
    for (i = 0; i < num_filas; i++)
    {
        for (j = 0; j < num_columnas; j++)
        {
            ft_printf("%d ", visited[i][j]);
        }
        ft_printf("\n");
    }
} */

/*	Validar si la poscion de visited[x][y] es valida 

	Es decir:
		-Verifica los limites de la matriz tanto vertical como horizontal
		-Verifica que no sea un muro('1')
		-Verfica que la posicion no haya sido visitada anteriormente
*/
bool is_valid_pos(t_game *game, int x, int y, bool visited[MAX_FILAS][MAX_COLUMNAS])
{
    if (x < 0 || x >= game->num_columnas)
        return (false);
    if (y < 0 || y >= game->num_filas)
        return (false);
    if (game->map[y][x] == '1')
        return (false);
    if (visited[y][x])
        return (false);
    return (true);
}

/* La funcion dfs se encarga de explorar el mapa desde una posicion 
	inical('P') y verificar si es posible llegar a la salida('E') 
	cumpliendo con la condicion de recojer todos los objetos('C').

	Utiliza un conjunto predefinido de movimientos (derecha,abajo, 
	izquierda, arriba) para explorar las posibles direcciones desde 
	la posición actual. 
	
	Calcula las nuevas coordenadas (new_x, new_y) según cada movimiento.

	Para cada dirección válida (verificada con is_valid_pos), realiza una 
	llamada recursiva a dfs con las nuevas coordenadas. Si alguna llamada
	recursiva retorna true, la función también retorna true, indicando 
	que se ha encontrado una ruta válida hacia la salida.
	Si ninguna dirección lleva a una solución válida, la función retorna 
	false.

	La función dfs retorna true si encuentra una ruta desde la 'P' hasta 
	la 'E', cumpliendo con todas las condiciones de recolección de objetos.
	Retorna false si no existe una ruta válida desde la posición actual 
	hacia la salida.

ft_printf("Estas en: (%d, %d)\n", x, y);
ft_printf("Coleccionable encontrado en: (%d, %d)\n", x, y);
ft_printf("Encontraste la salida CON TODOS los coleccionables\n");
ft_printf("Encontraste la salida pero SIN los coleccionables\n");
ft_printf("Retrocediendo desde (%d, %d)\n", x, y); 
*/
bool	dfs(t_game *game, int x, int y, 
	bool visited[MAX_FILAS][MAX_COLUMNAS], int *obj)
{
	int		i;
	int		new_x;
	int		new_y;

	visited[y][x] = true;
	if (game->map[y][x] == 'C')
		(*obj)--;
	if (game->map[y][x] == 'E')
	{
		if (*obj == 0)
			return (true);
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
	return (false);
}

/*	Se encarga de llamar a dfs y verificar si todas las celdas 'C' y 'E' 
	han sido visitadas 
*/
bool	is_valid_path(t_game *game)
{
	bool	visited[MAX_FILAS][MAX_COLUMNAS] = {false};
	bool	all_visited;
	int		i;
	int		j;
	int		obj;

	obj = game->obj_count;
	dfs(game, game->start.x, game->start.y, visited, &obj);
	all_visited = true;
	i = 0;
	while (i < game->num_filas)
	{
		j = 0;
		while (j < game->num_columnas)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E') 
				&& !visited[i][j])
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
	/* if (all_visited)
		ft_printf("Todas las celdas 'C' y 'E' han sido visitadas\n");
	else
		ft_printf("No todas las celdas 'C' y 'E' han sido visitadas\n"); 
    ft_printf("Matriz visited:\n");
    print_visited(visited, game->num_filas, game->num_columnas); */
	return (all_visited);
}