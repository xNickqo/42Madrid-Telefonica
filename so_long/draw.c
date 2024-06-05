/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:34:29 by niclopez          #+#    #+#             */
/*   Updated: 2024/06/05 17:02:52 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Función para cargar imágenes y verificar su carga
void load_images(t_game *game)
{
    printf("Cargando imágenes...\n");

    game->wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", &game->img_width, &game->img_height);
    game->floor = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm", &game->img_width, &game->img_height);
    game->player = mlx_xpm_file_to_image(game->mlx, "imgs/player.xpm", &game->img_width, &game->img_height);
    game->exit = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm", &game->img_width, &game->img_height);
    game->collectible = mlx_xpm_file_to_image(game->mlx, "imgs/collectible.xpm", &game->img_width, &game->img_height);
    
    if (!game->wall || !game->floor || !game->player || !game->exit || !game->collectible)
    {
        printf("Error al cargar las imágenes\n");
        exit(EXIT_FAILURE);
    
    }
    printf("(wall): %dx%d\n", game->img_width, game->img_height);
    printf("(floor): %dx%d\n", game->img_width, game->img_height);
    printf("(player): %dx%d\n", game->img_width, game->img_height);
    printf("(exit): %dx%d\n", game->img_width, game->img_height);
    printf("(collectible): %dx%d\n", game->img_width, game->img_height);
    printf("OK\n");
}


void free_images(t_game *game)
{
    printf("Liberando imagenes.\n");

    if (game->wall)
        mlx_destroy_image(game->mlx, game->wall);
    if (game->floor)
        mlx_destroy_image(game->mlx, game->floor);
    if (game->player)
        mlx_destroy_image(game->mlx, game->player);
    if (game->exit)
        mlx_destroy_image(game->mlx, game->exit);
    if (game->collectible)
        mlx_destroy_image(game->mlx, game->collectible);
}

// Función para dibujar el mapa y verificar las coordenadas
void draw_map(t_game *game)
{
    int i;
    int j;
    int x;
    int y;

    printf("Dibujando mapa...\n");

    i = 0;
    while (i < game->num_filas)
    {
        j = 0;
        while (j < game->num_columnas)
        {
            x = j * TILE_SIZE;
            y = i * TILE_SIZE;
            if (game->map[i][j] == '1')
            {
                printf("(%d, %d) - Pared\n", x, y);
                mlx_put_image_to_window(game->mlx, game->window, game->wall, x, y);
            }
            else if (game->map[i][j] == '0')
            {
                printf("(%d, %d) - Suelo\n", x, y);
                mlx_put_image_to_window(game->mlx, game->window, game->floor, x, y);
            }
            else if (game->map[i][j] == 'P')
            {
                printf("(%d, %d) - Jugador\n", x, y);
                mlx_put_image_to_window(game->mlx, game->window, game->player, x, y);
            }
            else if (game->map[i][j] == 'E')
            {
                printf("(%d, %d) - Salida\n", x, y);
                mlx_put_image_to_window(game->mlx, game->window, game->exit, x, y);
            }
            else if (game->map[i][j] == 'C')
            {
                printf("(%d, %d) - Coleccionable\n", x, y);
                mlx_put_image_to_window(game->mlx, game->window, game->collectible, x, y);
            }
            j++;
        }
        i++;
    }
    printf("OK\n");
}
