/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:04 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/29 16:02:11 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	return (1);
}

/*
int	main(void)
{
	int nb = 3;
	int power = 0;

	int resultado = ft_recursive_power(nb, power);
	printf("Mi funcion : %d\n", resultado);

	int resultadoPow = pow(nb, power);
	printf("Funcion Pow() de <math.h> : %d", resultadoPow);
}*/
