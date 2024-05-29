/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:26:18 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/26 15:49:11 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	acum;

	if (power < 0)
	{
		return (0);
	}
	else if (nb == 0 || power == 0)
	{
		return (1);
	}
	else if (power == 1)
	{
		return (nb);
	}
	i = 1;
	acum = 1;
	while (i <= power)
	{
		acum = acum * nb;
		i++;
	}
	return (acum);
}

/* 5 ^ 3 = 125
 * 5 * 5 * 5 = 125
 *
 * 2 ^ 0 = 0
 * 2 ^ 1 = 2
 * 2 ^ negative = 0
 * */
/*
int	main(void)
{
	int nb = 4;
	int power = 2;

	int resultado = ft_iterative_power(nb, power);
	printf("Mi funcion : %d\n", resultado);

	int resultadoPow = pow(nb, power);
	printf("Funcion Pow() de <math.h> : %d", resultadoPow);
}*/
