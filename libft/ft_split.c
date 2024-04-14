/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:59:04 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/14 23:24:58 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <string.h>

/*Reserva utilizando malloc() un array de strings resultante de 
 * separar la string 's' en substrings utilizando el caracter "c"
 * como delimitador. El array debe terminar con un puntero NULL
 *
 * Debe devolver un array de nuevas strings resultante de la 
 * separacion y NULL si falla la reserva de memoria.*/

/*Funcion para contar substrings*/

static int	count_substr(const char *s, char c)
{
	int	i;
	int	substr;

	i = 0;
	substr = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			substr++;
			i = 1;
		}
		else if (*s == c && i == 1)
			i = 0;
		s++;
	}
	return (substr);
}

/*Funcion para contar la longitud de las palabras hasta llegar al caracter
 * separador o el caracter sea nulo*/

static int	count_word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

/*Funcion para liberar memoria tanto de los substrings como del array principal
 * en caso de que la memoria falle*/

static char	**free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

/*FUNCION PRINCIPAL*/

char	**ft_split(char const *s, char c)
{
	int		num_str;
	int		index;
	int		len;
	char	**split;

	num_str = count_substr(s, c);
	split = (char **)malloc(sizeof(char *) * (num_str + 1));
	if (!split)
		return (NULL);
	index = 0;
	while (index < num_str)
	{
		while (*s == c)
			s++;
		len = count_word_len(s, c);
		split[index] = (char *)malloc(len + 1);
		if (!split[index])
			return (free_split(split));
		ft_strlcpy(split[index], s, len + 1);
		s += len;
		index++;
	}
	split[index] = NULL;
	return (split);
}
/*
int	main(void)
{
	char	s[] = "Hello World This is an Example";
	const char c = ' ';

	char **res = ft_split(s, c);

	int i = 0;
	while (res[i] != NULL)
	{
		printf("%s\n", res[i]);
		i++;
	}
}*/
