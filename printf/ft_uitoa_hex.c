/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:24:32 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/23 15:15:57 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

unsigned int	number_len_hex(unsigned int temp)
{
	unsigned int	len;

	len = 0;
	if (temp == 0)
		len = 1;
	else
		len = 0;
	while (temp != 0)
	{
		temp /= 16;
		len++;
	}
	return (len);
}

char	*ft_uitoa_hex(unsigned int n, int letra)
{
	char		*res;
	unsigned int	len;
	unsigned int	temp;
	const char	*hex_digits;

	len = number_len_hex(n);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	temp = n;
	if (letra == 0)
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	while (len > 0)
	{
		res[--len] = hex_digits[temp % 16];
		temp /= 16;
	}
	return (res);
}
