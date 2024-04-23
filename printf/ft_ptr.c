/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:02:03 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/23 14:40:25 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <stdint.h>

char	to_hex(int digit)
{
	if (digit >= 0 && digit <= 9)
		return ('0' + digit);
	else
		return ('a' + (digit - 10));
}

void	write_inverse(const char *str, int len, int *count)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
		(*count)++;
	}
}

void	ft_ptr(va_list args, int *count)
{
	void		*ptr;
	uintptr_t	ptr_val;
	char		buffer[20];
	int			len;
	char		digit;

	ptr = va_arg(args, void *);
	ptr_val = (uintptr_t)ptr;
	len = 0;
	while (ptr_val)
	{
		digit = ptr_val % 16;
		buffer[len] = to_hex(digit);
		ptr_val /= 16;
		len++;
	}
	buffer[len++] = 'x';
	buffer[len++] = '0';
	write_inverse(buffer, len, count);
}
