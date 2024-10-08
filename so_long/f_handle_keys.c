/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 23:33:01 by niclopez          #+#    #+#             */
/*   Updated: 2024/08/18 18:23:00 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	
------------------------------------------------------------------------------
			El boton X hara una finalizacion limpia del programa	
------------------------------------------------------------------------------
*/

int	handle_exit(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
	return (0);
}

/*	
------------------------------------------------------------------------------
		La tecla ESC(65307 en Linux) hara una finalizacion limpia del 
		programa y se estableceran que teclas seran las de movimiento
------------------------------------------------------------------------------
*/

int	handle_key(int key, t_game *game)
{
	if (key == 65307)
	{
		free_images(game);
		exit(0);
	}
	else if (key == 'w')
		move_up(game);
	else if (key == 's')
		move_down(game);
	else if (key == 'a')
		move_left(game);
	else if (key == 'd')
		move_right(game);
	draw_map(game);
	return (0);
}
