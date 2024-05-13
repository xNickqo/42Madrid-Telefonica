/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:50:19 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/13 20:50:55 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <unistd.h>

/*FUNCIONES DE AYUDA*/

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/*La funcion strchr() devuelve un puntero a la primera ocurrencia del caracter
 * c en la cadena de caracteres s
 *
 * Devuelve un puntero al elemento de la cadena con el caracter coincidente
 * o null si el caracter no se ha encontrado*/

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	if (!str)
		return (NULL);
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

/*Reserva con malloc() y devuelve una nueva string, formada por la
 * concatenacion de s1 y s2*/

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	res = ft_join(res, s1, s2);
	free(s1);
	return (res);
}

char	*ft_join(char *res, char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	res[ft_strlen(s1) + i] = '\0';
	return (res);
}
