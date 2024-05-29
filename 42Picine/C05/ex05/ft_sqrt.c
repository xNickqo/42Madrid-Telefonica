/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:44:53 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/29 16:07:03 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int	ft_sqrt(int nb)
{
	int	mid;

	mid = 0;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	while (mid <= nb / 2 && mid <= 46340)
	{
		if (mid * mid == nb)
			return (mid);
		mid++;
	}
	return (0);
}
/*
int	main(void)
{
	int x = ft_sqrt(49);
	printf("%d\n", x);

	int y = sqrt(49);
	printf("%d", y);
}*/
