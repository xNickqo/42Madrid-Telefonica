/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:51:09 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/26 19:01:05 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*Cada numero es igual a la suma de sus dos anteriores:
 *----------- Sucesion de FIBONACCI ------------------
 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 ... 
 
 ft_fibonacci(1) = 1
 ft_fibonacci(index) = ft_fibonacci(index-1) + ft_fibonacci(index-2)
 */

/*void	fibonacci(int penultimo, int ultimo, int n)
{
	int actual;
	if (n > 1)
	{	
		actual = penultimo + ultimo;
		printf("%d", actual);
		printf(", ");
		n--;
		fibonacci(ultimo, actual, n);
	}
}*/

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
int	main(void)
{
	fibonacci(0,1,11);

	printf("\n");

	int resultado = ft_fibonacci(11);
	printf("El resultado de la posicion seleccionada es: %d", resultado);
}*/
