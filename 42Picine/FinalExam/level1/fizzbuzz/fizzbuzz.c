/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:33:45 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/29 23:54:48 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

void	ft_write(char	*str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	main(void)
{
	int i;

	i = 1;
	while (i < 100)
	{
		if (i % 4 == 0 && i % 7 == 0)
			ft_write("fizzbuzz");
		else if (i % 4 == 0)
			ft_write("fizz");
		else if (i % 7 == 0)
			ft_write("buzz");
		else
			ft_putnbr(i);
		ft_write("\n");
		i++;
	}
}
