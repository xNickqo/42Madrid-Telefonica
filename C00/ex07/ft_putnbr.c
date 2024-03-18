/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:02:11 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/23 13:08:00 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write_char('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		write_char(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		write_char(nb + 48);
	}
}
/*
int main(void)
{
	ft_putnbr(1);
}*/
