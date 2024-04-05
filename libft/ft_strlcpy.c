/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:15:36 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/03 17:39:40 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

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
/*
int main(void){
	char origen[15] = "Manuela";
	char destino[20] = "Adios";
	int x;
	x = ft_strlcpy(destino, origen, 2);
	printf("%d\n", x);
	printf("%s\n", origen);
	printf("%s", destino);
}*/
