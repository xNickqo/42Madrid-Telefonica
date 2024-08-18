/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:18:56 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/05 19:03:39 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

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
/*
int	main(void)
{
	//Mi funcion
	char *s = "hola me llamo nico";
	char c = 'm';
	char *res = ft_strchr(s, c);
	printf("%s\n\n", res);

	//Funcion original
	char *s1 = "hola me llamo nico";
	char c1 = 'm';
	char *reso = strchr(s1, c1);
	printf("%s", reso);
}*/
