/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:09:29 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/26 17:57:48 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

/*FUNCIONES DE AYUDA*/

/*La funcion strdup() reserva espacio de almacenamiento para una copia de
 * serie llamando a malloc. Se espera que el argumento de serie para esta
 * funcion contenga un caracter '\0' que marque el final de la serie.
 * Recordar liberar con free() */

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(str) + 1;
	dest = (char *)malloc(len);
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, str, len);
	return (dest);
}

/* Copia una cadena de origen en un destino de tamaño limitado, asegurándose 
 * de que el destino esté terminado con un carácter nulo y devolviendo la 
 * longitud de la cadena original. 
 *
 * Es útil para evitar desbordamientos de búfer al copiar cadenas.*/

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while ((i < destsize - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

/*La funcion strchr() devuelve un puntero a la primera ocurrencia del caracter
 * c en la cadena de caracteres s
 *
 * Devuelve un puntero al elemento de la cadena con el caracter coincidente
 * o null si el caracter no se ha encontrado*/

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
