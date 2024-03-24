/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:10:45 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/24 15:47:47 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <stddef.h>

/*La funcion escanea n bytes del area de memoria de str[] y si encuentra
 * el caracter c devuelve un puntero a la direccion de memoria donde lo
 * ha encontrado, sino encuentra ninguna ocurrencia devuelve NULL*/

char	*ft_memchr(const char *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char *str = "Hola me llamo Nicolas y Perni es guapa";
	char c = 'P';

	char *res = ft_memchr(str, c, 100);
	printf("%s\n", res);
	if (res != NULL)
		printf("%c\n", *res);
	else
		printf("No se ha encontrado el caracter '%c'\n", c);
}*/
