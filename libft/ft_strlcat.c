/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:35:44 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/21 15:26:09 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Esta funcion garantiza que la cadena termina en '\0', y no haya un 
 * desbordamiento de buffer */

#include <stdio.h>
#include <string.h>
#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	len_dest = i;
	while (src[j])
		j++;
	len_src = j;
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (len_dest < size)
		dest[i] = '\0';
	return (len_dest + len_src);
}
/*Primero calculamos la longitud de dest y la de src
 *
 * concatenamos  src a dest, asegurando no exceder size - 1
 *
 * Agregamos el caracter nulo al final
 *
 * y retornamos el tamaño concatenado*/
/*
int	main(void)
{
	char	a[] = "Hello";
	char	b[] = "World";
	int x =	ft_strlcat(a, b, 2);
	printf("ft_strlcat() : %d \n", x);
	printf("dest = %s\n",  a);

	char	c[] = "Hello";
	char	d[] = "World";
	int y = strlcat(c, d, 2);
	printf("strlcat()    : %d\n", y);
	printf("dest = %s\n", c);
}*/
