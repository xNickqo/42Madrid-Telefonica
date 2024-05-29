/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:59:38 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/21 21:02:58 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	char	digitos[50];
	int		i;
	int		neg;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (len <= 1)
		return ;
	neg = 1;
	while (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	i = 0;
	while (nbr != 0)
	{
		digitos[i] = base[(nbr % len) * neg];
		nbr = nbr / len;
		i++;
	}
	while (i >= 0)
		write(1, &digitos[--i], 1);
}
/*
int	main(void)
{
	ft_putnbr_base(5226, "poniguay");
}*/
