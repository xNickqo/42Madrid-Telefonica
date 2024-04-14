/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:04:35 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/14 23:10:01 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*Copia "len" bytes de "src" en "dest". El comportamiento no esta definido
 * si la copia tiene lugar entre objetos que se solapan. La funcion memmove
 * permite copiar entre objetos que pueden solaparse.*/

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[100] = "Hola";
	char	*src = "Mundo";
	size_t	lendest = ft_strlen(dest);
	size_t	lensrc = ft_strlen(src);
	size_t	len = lendest + lensrc;
	
	//dest + lendest para recorrer "hola"
	//src es lo que se quiere copiar dentro de dest
	//y lenstc + 1 para copiar todos los caracteres de src(incluido
	//el caracter null)
	ft_memcpy(dest + lendest, src, lensrc + 1);
	printf("Destino: %s", dest);
}*/
