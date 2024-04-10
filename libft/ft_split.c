/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:59:04 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/05 21:09:58 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <string.h>

/*Reserva utilizando malloc() un array de strings resultante de 
 * separar la string 's' en substrings utilizando el caracter "c"
 * como delimitador. El array debe termianr con un puntero NULL
 *
 * Debe devolver un array de nuevas strings resultante de la 
 * separacion y NULL si falla la reserva de memoria.*/

static int	count_substr(const char *s, char c)
{
	int	i;
	int	substr;

	i = 1;
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
	return (substr + 1);
}

char	**ft_split(char const *s, char c)
{
	int		num_str;
	int		index;
	int		len;
	const char	*start;
	char		**split;

	num_str = count_substr(s, c);
	split = (char **)malloc(num_str + 1);
	if (!split)
		return (NULL);
	index = 0;
	len = 0;
	start = s;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (len > 0)
			{
				split[index] = (char *)malloc(len + 1);
				if (!split[index])
					return (0);
				ft_strlcpy(split[index], start, len + 1);
				split[index][len] = '\0';
				index++;
				len = 0;
			}
			start = s + 1;
		}
		else
		{
			len++;
		}
		s++;
	}
	if (len > 0)
	{
		split[index] = (char *)malloc(len + 1);
		ft_strlcpy(split[index], start, len + 1);
		index++;
	}
	split[index] = NULL;
	return (split);
}
/*
int	main(void)
{
	char	s[] = "Hello, World, This, is, an, Example";
	const char c = ',';

	char **res = ft_split(s, c);

	int i = 0;
	while (res[i] != NULL)
	{
		printf("%s\n", res[i]);
		i++;
	}
}*/
