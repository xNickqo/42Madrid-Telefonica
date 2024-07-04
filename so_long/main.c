/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:06:06 by niclopez          #+#    #+#             */
/*   Updated: 2024/07/04 23:39:17 by niclopez         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_game	game;

	is_ber_file(argc, argv);
	read_map(argv[1], &game);

	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		ft_printf("Error al inicializar Minilibx\n");
		return (1);
	}
	game.width = game.num_columnas * TILE_SIZE;
	game.height = game.num_filas * TILE_SIZE;
	game.window = mlx_new_window(game.mlx, game.width, game.height, "Juego");
	if (game.window == NULL)
	{
		ft_printf("Error al crear la ventana\n");
		return (1);
	}

	load_images(&game);

	game.p.x = game.start.x;
	game.p.y = game.start.y;
	game.p.collected = 0;
	game.move_count = 0;

	draw_map(&game);

	mlx_hook(game.window, 17, 0, handle_exit, &game);
	mlx_key_hook(game.window, handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
