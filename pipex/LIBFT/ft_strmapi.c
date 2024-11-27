/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:34:22 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/07 16:40:02 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/* Esta funcion sirve para manipular caracteres de la string 's' con
 * funciones 'f'(unsigned int, char) y devuelve una nueva string.*/

/*
char	convert(unsigned int i, char c)
{
	if (ft_isalpha(c))
		return ft_toupper(c);
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*res;
	size_t	i;

	len = ft_strlen(s);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[len] = '\0';
	return (res);
}
/*
int	main(void)
{
	const char	*original = "Hello World";
	char		*res = ft_strmapi(original, &convert);
	if (res)
	{
		printf("Original : %s\n", original);
		printf("Resultado : %s\n", res);
		free(res);
	}
	else
		printf("Error");
}*/
