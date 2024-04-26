/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:05:21 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/26 18:25:13 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

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
	static char	*buffer;
	int			bytes_read;
	char		*line;
	int			i;
	int			len;
	char		*temp;

	len = BUFFER_SIZE;
	if(buffer)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
		{
			line = (char *)malloc(len + 1);
			if (line == NULL)
			{
				free(buffer);
				buffer = NULL;
				return (NULL);
			}
			ft_memcpy(line, buffer, i);
			line[i] = '\0';
			temp = ft_strdup(buffer + i + 1);
			free(buffer);
			buffer = temp;
			return (line);
		}
		free(buffer);
		buffer = NULL;
	}

	line = (char *)malloc(len + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while ((bytes_read = read(fd, line + i, BUFFER_SIZE)) > 0)
	{
		i += bytes_read;
		len += BUFFER_SIZE;
		if (i >= len)
		{
			temp = my_realloc(line, len - BUFFER_SIZE, len);
			if (temp == NULL)
			{
				free(line);
				return(NULL);
			}
			line = temp;
		}
		i = 0;
		while (i < bytes_read)
		{
			if (line[i] == '\n')
			{
				line[i] = '\0';
				buffer = ft_strdup(line + i + 1);
				if (buffer == NULL)
				{
					free(line);
					return (NULL);
				}
				return (line);
			}
			i++;
		}
	}
	if (bytes_read == 0 && i > 0)
	{
		line[i] = '\0';
		return (line);
	}
	free(line);
	return (NULL);
}

int	main()
{
	int	fd = open("ejemplo.txt", O_RDONLY);

	char	*line;;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linea leida: %s\n", line);
		free(line);
	}
	close(fd);
}
