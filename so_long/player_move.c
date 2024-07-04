/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:42:47 by niclopez          #+#    #+#             */
/*   Updated: 2024/07/05 00:07:21 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
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

void	move_up(t_game *game)
{
	game->player = game->player_back;
	move_player(game, game->p.x, game->p.y - 1);
}

void	move_down(t_game *game)
{
	game->player = game->player_front;
	move_player(game, game->p.x, game->p.y + 1);
}

void	move_left(t_game *game)
{
	game->player = game->player_left;
	move_player(game, game->p.x - 1, game->p.y);
}

void	move_right(t_game *game)
{
	game->player = game->player_right;
	move_player(game, game->p.x + 1, game->p.y);
}
