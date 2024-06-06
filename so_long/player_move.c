/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:42:47 by niclopez          #+#    #+#             */
/*   Updated: 2024/06/06 22:25:17 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_player(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == '1') // Si es un muro, no se mueve
        return ;
    if (game->map[new_y][new_x] == 'C') // Recoge coleccionable
        game->p.collected++;
    if (game->map[new_y][new_x] == 'E')
    {
        if (game->p.collected == game->obj_count)
        {
            mlx_destroy_window(game->mlx, game->window);
            exit(0);
        }
        return ;
    }
    game->map[game->p.y][game->p.x] = '0'; // Borra la posición anterior
    game->p.x = new_x;
    game->p.y = new_y;
    game->map[new_y][new_x] = 'P'; // Actualiza la nueva posición
}

void    move_up(t_game *game)
{
    move_player(game, game->p.x, game->p.y - 1);
}

void    move_down(t_game *game)
{
    move_player(game, game->p.x, game->p.y + 1);
}

void    move_left(t_game *game)
{
    move_player(game, game->p.x - 1, game->p.y);
}

void    move_right(t_game *game)
{
    move_player(game, game->p.x + 1, game->p.y);
}
