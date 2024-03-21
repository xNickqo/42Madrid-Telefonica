/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:15:37 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/21 16:52:28 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

/*Esta funcion llenara el dest[] con el value y el tamaño establecido
 *
 * Retorna un puntero de dest(retornar puntero al principio del array)
 *
 *
 * *dest = Es un puntero al bloque de memoria que se va a llenar
 * value = Es el valor que se le va a asignar a cada byte del bloque de mem
 * len = Es el numero de bytes que se llenara con el value especificado*/

void	*ft_memset(void *dest, int value, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	temp = dest;
	i = 0;
	while (i < len)
	{
		*temp++ = value;
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	//Mi funcion
	char dest[10];
	int value = 33;
        size_t len = 5;

	ft_memset(dest, value, len);	
	
	for (int i = 0; i < len; i++) 
	{
		printf("%d ", dest[i]);
		printf("\n");
	}
        

	printf("\n");
	
	//Funcion original
	char dest1[10];
	int value1 = 33;
	size_t len1 = 5;

	memset(dest1, value1, len1);

	for (int y = 0; y < len1; y++)
	{
		printf("%d ", dest1[y]);
		printf("\n");
	}
}*/
