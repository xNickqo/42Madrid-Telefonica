/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:06:06 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/16 15:14:53 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

int	handle_key(int key, void *param)
{
	(void)param;
	if (key == 53 || key == 65307)
		exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	/* mlx_init() devuelve un puntero que se utiliza como identificador
	 * para las futuras operaciones Minilibx*/
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return 1;
	
	
	/* mlx_new_window() creara una nueva ventana con el tamaño
	 * especificado y el titulo dado*/
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Mi minijuego");
	if (win_ptr == NULL)
		return 1;
	
	
	/* mlx_pixel_put() dibuja un pixel en las cordenadas de la ventana*/
	mlx_pixel_put(mlx_ptr, win_ptr, 0, 0, 0xFFFFFF);
	
	
	/* mlx_key_hook() llama a una funcion cuando se presione una tecla
	 * en la ventana especificada por win_ptr*/
	mlx_key_hook(win_ptr, handle_key, NULL);


	/* Ciclo de eventos de minilibx. Debes llamar a esta funcion
	 * despues de haber configurado tus ventanas y eventos*/
	mlx_loop(mlx_ptr);
	return 0;
}
