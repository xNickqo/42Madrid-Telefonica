/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:06:06 by niclopez          #+#    #+#             */
/*   Updated: 2024/06/03 22:47:32 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

int	handle_key(int key, t_game *game)
{
	(void)game;
	if (key == 65307)
		exit(0);
	return (0);
}

void	is_ber_file(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Debes usar un solo argumento tal que: %s <archivo>.ber\n", argv[0]);
        exit(EXIT_FAILURE);
	}
	if(!strstr(argv[1], ".ber"))
	{
		printf("La extension del archivo es invalida\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;
	is_ber_file(argc, argv);
	read_map(argv[1], &game);
	game.width = game.num_columnas * TILE_SIZE;
	game.height = game.num_filas * TILE_SIZE;
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		printf("Error al inicializar Minilibx\n");
		return (1);
	}
	game.window = mlx_new_window(game.mlx, game.width, game.height, "Mi minijuego");
	if (game.window == NULL)
	{
		printf("Error al crear la ventana\n");
		return (1);
	}
	draw_map(&game);
	mlx_key_hook(game.window, handle_key, &game);
	mlx_loop(game.mlx);
	return 0;
}
