/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:59:48 by niclopez          #+#    #+#             */
/*   Updated: 2024/08/13 19:27:53 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	obj_cond(t_game *game, int x, int y)
{
	int		obj;

	obj = game->obj_count;
	if (game->map[y][x] == 'C')
		obj--;
	if (game->map[y][x] == 'E' && obj == 0)
		return (true);
	return (false);
}

void	init_moves(t_pos moves[4])
{
	moves[0].x = 0;
	moves[0].y = 1;
	moves[1].x = 1;
	moves[1].y = 0;
	moves[2].x = 0;
	moves[2].y = -1;
	moves[3].x = -1;
	moves[3].y = 0;
}

/*	
------------------------------------------------------------------------------
	Validar si la poscion de visited[x][y] es valida 

	Es decir:
		-Verifica los limites de la matriz tanto vertical como horizontal
		-Verifica que no sea un muro('1')
		-Verfica que la posicion no haya sido visitada anteriormente
------------------------------------------------------------------------------
*/
bool	valid(t_game *game, int x, int y, bool visited[MX_ROWS][MX_COLS])
{
	if (x < 0 || x >= game->cols)
		return (false);
	if (y < 0 || y >= game->rows)
		return (false);
	if (game->map[y][x] == '1')
		return (false);
	if (visited[y][x])
		return (false);
	return (true);
}

/* 
--------------------------------------------------------------------------
	La funcion dfs se encarga de explorar el mapa desde una posicion 
	inical('P') y verificar si es posible llegar a la salida('E') 
	cumpliendo con la condicion de recojer todos los objetos('C').

	Utiliza un conjunto predefinido de movimientos (derecha,abajo, 
	izquierda, arriba) para explorar las posibles direcciones desde 
	la posición actual. 
	
	Calcula las nuevas coordenadas (new_x, new_y) según cada movimiento.

	Para cada dirección válida (verificada con valid), realiza una 
	llamada recursiva a dfs con las nuevas coordenadas. Si alguna llamada
	recursiva retorna true, la función también retorna true, indicando 
	que se ha encontrado una ruta válida hacia la salida.
	Si ninguna dirección lleva a una solución válida, la función retorna 
	false.

	La función dfs retorna true si encuentra una ruta desde la 'P' hasta 
	la 'E', cumpliendo con todas las condiciones de recolección de objetos.
	Retorna false si no existe una ruta válida desde la posición actual 
	hacia la salida.
----------------------------------------------------------------------------
*/
/*
ft_printf("Estas en: (%d, %d)\n", x, y);
ft_printf("Coleccionable encontrado en: (%d, %d)\n", x, y);
ft_printf("Encontraste la salida CON TODOS los coleccionables\n");
ft_printf("Encontraste la salida pero SIN los coleccionables\n");
ft_printf("Retrocediendo desde (%d, %d)\n", x, y); 
*/

bool	dfs(t_game *game, int x, int y,
	bool visited[MX_ROWS][MX_COLS])
{
	int		i;
	int		new_x;
	int		new_y;
	t_pos	moves[4];

	visited[y][x] = true;
	obj_cond(game, x, y);
	init_moves(moves);
	i = 0;
	while (i < 4)
	{
		new_x = x + moves[i].x;
		new_y = y + moves[i].y;
		if (valid(game, new_x, new_y, visited))
		{
			if (dfs(game, new_x, new_y, visited))
				return (true);
		}
		i++;
	}
	return (false);
}
