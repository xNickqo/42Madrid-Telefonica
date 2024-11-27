/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:09:55 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/07 16:30:57 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h>

/*Asigna memoria a un array de 'nmemb' elementos y 'size' tamaño de los datos
 * y se inicializa en 0*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	size_t	i;
	char	*temp;
	void	*ptr;

	total = nmemb * size;
	if (total < SIZE_MAX)
	{
		ptr = (char *)malloc(total);
		if (ptr == 0)
			return (0);
		i = 0;
		temp = ptr;
		while (i < total)
		{
			temp[i] = 0;
			i++;
		}
		return (ptr);
	}
	else
		return (NULL);
}
/*
int	main(void)
{
	size_t	num_elementos = 5;
	size_t	size = 5;

	int	*array = ft_calloc(num_elementos, size);

	printf("Array despues del calloc(): \n");
	for (size_t i = 0; i < num_elementos; i++)
	{
		printf("%d\n", array[i]);
	}
	free(array);
}*/
