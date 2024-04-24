/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:05:21 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/24 18:57:17 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

/*FUNCIONALIDAD BASICA:
1. Lectura de una linea: la funcion lee la siguiente linea del archivo
	de texto apuntado por un descriptor de archivo
2. Almacenamiento en un buffer: La linea leida se almacena en un
	buffer proporcionado por el usuario, junto con la informacion
	sobre si se a alcanzado el final del archivo (EOF)
3. Maneja de fin de archivo: Cuando se alcanza el final del archivo
	la funcion indica que ya no hay mas lineas que leer
4. Manejo de lineas largas: La funcion tambien puede manejar lineas
	de longitud arbitraria, dividiendolas segun el tamaño del buffer
5. Retorno del estado: La funcion devuelve un valor que indica si se
	ha leido una linea exitosamente, si se ha alcanzado el final del
	archivo, o si ha ocurrido algun error.*/

char	*get_next_line(int fd)
{
	char	*line = NULL;
	char	*line_tmp;
	static char	buffer[42];

	line_tmp = malloc(buffer + 1);
	if (line_tmp == NULL)
	{
		free(line);
		return (NULL);
	}
	line = line_tmp;
}

int	main()
{
	int	fd = open("ejemplo.txt", O_RDONLY);

	int	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Linea leida: %s", line);
		free(line);
	}
}
