/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_player_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:42:47 by niclopez          #+#    #+#             */
/*   Updated: 2024/08/14 19:51:50 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
-----------------------------------------------------------------------------
	Funcion que gestiona el movimiento del personaje:
		-Si encuentras un muro NO AVANCES
		-Si encuentras un coleccionable recolectalo
		-si encuentras la salida y el numero de collecionables recolectados
			es igual al numero de coleccionables totales PUEDES SALIR (y se 
			cierra el programa), en caso contrario NO AVANCES.
		
		Se actualiza la posicion del personaje cada vez que avance
		de posicion coloca '0' en la posicion anterior y 'P' en la nueva.

		Contador de pasos :)
		
-----------------------------------------------------------------------------
*/

void	player_move(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		ft_printf("¡Encontraste un coleccionable!\n");
		game->p.collected++;
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->p.collected == game->obj_count)
		{
			ft_printf("Encontraste la salida con TODOS los coleccionables\n");
			mlx_destroy_window(game->mlx, game->window);
			exit(0);
		}
		ft_printf("Te faltan los coleccionables CRACK!\n");
		return ;
	}
	game->map[game->p.y][game->p.x] = '0';
	game->p.x = new_x;
	game->p.y = new_y;
	game->map[new_y][new_x] = 'P';
	game->move_count++;
	ft_printf("%d\n", game->move_count);
}

/*
-----------------------------------------------------------------------------
						w = move_up    (y - 1)
						s = move_down  (y + 1)
						a = move_left  (x - 1)
						d = move_right (x + 1)
-----------------------------------------------------------------------------
*/

void	move_up(t_game *game)
{
	game->player = game->player_back;
	player_move(game, game->p.x, game->p.y - 1);
}

void	move_down(t_game *game)
{
	game->player = game->player_front;
	player_move(game, game->p.x, game->p.y + 1);
}

void	move_left(t_game *game)
{
	game->player = game->player_left;
	player_move(game, game->p.x - 1, game->p.y);
}

void	move_right(t_game *game)
{
	game->player = game->player_right;
	player_move(game, game->p.x + 1, game->p.y);
}
