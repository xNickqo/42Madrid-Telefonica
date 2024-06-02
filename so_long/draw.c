/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:34:29 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/22 02:40:16 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void draw_tile(t_game *game, int x, int y, int color) {
    int i;
    int j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            mlx_pixel_put(game->mlx, game->window, x * TILE_SIZE + j, y *TILE_SIZE + i, color);
            j++;
        }
        i++;
    }
}

void draw_map(t_game *game) {
    int i;
    int j;

    i = 0;
    while (i < game->num_filas)
    {
        j = 0;
        while (j < game->num_columnas)
        {
            if (game->map[i][j] == '1')
                draw_tile(game, j, i, 0xFF0000); // Rojo para muros
            else if (game->map[i][j] == '0')
                draw_tile(game, j, i, 0x00FF00); // Verde para suelo
            else if (game->map[i][j] == 'P')
                draw_tile(game, j, i, 0x0000FF); // Azul para jugador
            else if (game->map[i][j] == 'E')
                draw_tile(game, j, i, 0xFFFF00); // Amarillo para salida
            else if (game->map[i][j] == 'C')
                draw_tile(game, j, i, 0xFF00FF); // Magenta para coleccionables
            j++;
        }
        i++;
    }
}