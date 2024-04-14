/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:10:45 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/14 22:07:51 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*La funcion escanea n bytes del area de memoria de str[] y si encuentra
 * el caracter c devuelve un puntero a la direccion de memoria donde lo
 * ha encontrado, sino encuentra ninguna ocurrencia devuelve NULL*/

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*str_temp;
	char	c_char;

	i = 0;
	c_char = (char)c;
	while (i < n)
	{
		str_temp = (char *)str++;
		if (*str_temp == c_char)
			return ((void *)str_temp);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char *str = "Hola me llamo Nicolas y Perni es guapa";
	char c = 'P';

	char *res = ft_memchr(str, c, 5);
	printf("%s\n", res);
	if (res != NULL)
		printf("%c\n", *res);
	else
		printf("No se ha encontrado el caracter '%c'\n", c);
	//OUTPUT: res* = Perni
}*/
