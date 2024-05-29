/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:55:09 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/24 19:40:31 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*Convertir el int nb a tipo long para manejar los limites de bytes y el
 * overflow.
 *
 * Comprobar el manejo del numero 0 y los nb negativos.
 *
 * Mientras 
 * */
void	ft_putchar(char n)
{
	write(1, &n, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = nb * -1;
	}
	else
	{
		n = nb;
	}
	if (n / 10 != 0)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
/*
int main(void)
{
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-42);
	write(1, "\n", 1);
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
}*/
