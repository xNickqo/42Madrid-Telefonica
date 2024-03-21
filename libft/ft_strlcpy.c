/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:15:36 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/21 16:54:00 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	n;
	size_t	count;

	if (dest == 0 && destsize == 0)
		return (0);
	if (destsize < (size_t)ft_strlen(dest))
		return (destsize + (size_t)ft_strlen((char *)src));
	i = ft_strlen(dest);
	n = 0;
	count = ft_strlen(dest) + ft_strlen((char *)src);
	while ((i < destsize - 1) && src[n] != '\0')
	{
		dest[i] = src[n];
		n++;
		i++;
	}
	dest[i] = '\0';
	return (count);
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
