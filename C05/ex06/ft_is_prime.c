/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:18:33 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/01 00:08:11 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	int num = 7;
	int x = ft_is_prime(num);

	if (ft_is_prime(num) == 1)
		printf("el numero %d SI es primo\n", num);
	else
		printf("el numero %d NO es primo\n", num);
	
	num = 0;
	while (num < 100)
	{
		if (ft_is_prime(num))
		{
			printf("%d ,", num);
		}
		num++;
	}
}*/
