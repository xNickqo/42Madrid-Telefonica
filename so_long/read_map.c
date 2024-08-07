/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 02:35:29 by niclopez          #+#    #+#             */
/*   Updated: 2024/07/05 00:57:08 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	read_map(char *filename, t_game *game)
{
	int		fd;

	fd = open_file(filename);
	read_file(fd, game);
	if (!map_validator(game))
	{
		ft_printf("MAPA NO VALIDO!\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	ft_printf("El mapa es valido. OK!\n");
}
