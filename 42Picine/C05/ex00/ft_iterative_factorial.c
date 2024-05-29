/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:12:45 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/27 17:12:53 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	resultado;

	resultado = 1;
	if (nb == 1 || nb == 0)
	{
		return (1);
	}
	else if (nb < 0)
	{
		return (0);
	}
	else
	{
		while (nb > 0)
		{
			resultado *= nb;
			nb--;
		}
		return (resultado);
	}
}

/*	5! = 5 * 4!
 *	   = 5 * (4 * 3!)
 *	   = 5 * (4 * (3 * 2!))
 *	   = etc etc etc*/

/*int	main(void)
{
	 *---------- FACTORIAL ------------
	 * 5! -> 5*4*3*2*1 		5 * 4! = 5!
	 * 4! -> 4*3*2*1
	 * 3! -> 3*2*1
	 * 2! -> 2*1
	 * 1! -> 1
	 * 0! -> 0

	int nb = 5;
	int resultado;

	resultado = ft_iterative_factorial(nb);
	printf("%d", resultado);
}*/
