/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:21:27 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/01 01:40:54 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	if (n >= 10)
		putnbr(n / 10);
	char c = n % 10 + '0';
	write(1, &c, 1);
}

int main(void)
{
	putnbr(2200);
}


