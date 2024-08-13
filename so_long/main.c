/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:06:06 by niclopez          #+#    #+#             */
/*   Updated: 2024/08/13 19:23:20 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_ber_file(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Error, debe ser: %s <archivo>.ber\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (!strstr(argv[1], ".ber"))
	{
		ft_printf("La extension del archivo es invalida\n");
		exit(EXIT_FAILURE);
	}
}

void	init_game(t_game *game, char *map_path)
{
	read_map(map_path, game);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_printf("Error al inicializar Minilibx\n");
	game->height = game->rows * TILE_SIZE;
	game->width = game->cols * TILE_SIZE;
	game->window = mlx_new_window(game->mlx, game->width, game->height, "");
	if (game->window == NULL)
		ft_printf("Error al crear la ventana\n");
	load_images(game);
	game->p.x = game->start.x;
	game->p.y = game->start.y;
	game->p.collected = 0;
	game->move_count = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	is_ber_file(argc, argv);
	init_game(&game, argv[1]);
	draw_map(&game);
	mlx_hook(game.window, 17, 0, handle_exit, &game);
	mlx_key_hook(game.window, handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
