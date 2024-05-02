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

static char *read_from_file(int fd)
{
    int bytes_read;
    char *buffer;
    char   *temp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (buffer == NULL)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read >= BUFFER_SIZE)
        {
            temp = realloc(buffer, (BUFFER_SIZE * 2) + 1);
            if (temp == NULL)
                return (free(buffer), NULL);
            buffer = temp;
        }
        if (bytes_read <= 0)
            return (free(buffer), NULL);
        buffer[bytes_read] = '\0';
        //printf("buffer: %s\n", buffer);
    }
    if (bytes_read < 0)
        return (free(buffer), NULL);
    return (buffer);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    char *newline;

    buffer = NULL;
    if (buffer == NULL)
    {
        buffer = read_from_file(fd);
        if (buffer == NULL)
            return (NULL);
    }
    if (buffer[0] == '\0')
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    newline = ft_strchr(buffer, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
        line = ft_strdup(buffer);
        if (line == NULL)
            return (NULL);
        buffer = ft_strdup(newline + 1);
        if (buffer == NULL)
            return (NULL);
        return (line);
    }
    else
    {
        if (buffer[0] != '\0')
        {
            line = ft_strdup(buffer);
            if (line == NULL)
                return NULL;
        }
        else
        {
            line = NULL;
        }
        free(buffer);
        buffer = NULL;
        return (line);
}

}

/* int main(void)
{
    int fd = open("ejemplo.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Linea leida:---%s---\n", line);
        free(line);
    }
    close(fd);
    return 0;
}  */

