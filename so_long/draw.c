/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:34:29 by niclopez          #+#    #+#             */
/*   Updated: 2024/06/28 18:00:17 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_images(t_game *game)
{
    game->wall = mlx_xpm_file_to_image(game->mlx, "imgs/xpm/wall.xpm", 
		&game->img_width, &game->img_height);
    game->floor = mlx_xpm_file_to_image(game->mlx, "imgs/xpm/floor.xpm", 
		&game->img_width, &game->img_height);
    game->player = mlx_xpm_file_to_image(game->mlx, "imgs/xpm/player_front.xpm", 
		&game->img_width, &game->img_height);
    game->exit = mlx_xpm_file_to_image(game->mlx, "imgs/xpm/exit.xpm", 
		&game->img_width, &game->img_height);
    game->collectible = mlx_xpm_file_to_image(game->mlx, 
		"imgs/xpm/collectable.xpm", &game->img_width, &game->img_height);
    
    if (!game->wall || !game->floor || !game->player 
		|| !game->exit || !game->collectible)
    {
        ft_printf("Error al cargar las imágenes\n");
        exit(EXIT_FAILURE);
    }
}


void free_images(t_game *game)
{
    ft_printf("Liberando imagenes... ");
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
	ft_printf("OK.\n");
}

void draw_map(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < game->num_filas)
	{
		j = 0;
		while (j < game->num_columnas)
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall, x, y);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->floor, x, y);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->player, x, y);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit, x, y);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->collectible, x, y);
			j++;
		}
		i++;
	}
}
