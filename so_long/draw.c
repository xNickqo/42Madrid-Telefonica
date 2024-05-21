/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:34:29 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/21 18:56:00 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

void draw_tile(t_game *game, int x, int y, int color) {
    int i, j;

    for (i = 0; i < TILE_SIZE; i++) {
        for (j = 0; j < TILE_SIZE; j++) {
            mlx_pixel_put(game->mlx, game->window, x * TILE_SIZE + j, y * TILE_SIZE + i, color);
        }
    }
}

void draw_map(t_game *game) {
    int i, j;

    for (i = 0; i < game->num_filas; i++) {
        for (j = 0; j < game->num_columnas; j++) {
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
        }
    }
}