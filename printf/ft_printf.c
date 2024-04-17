/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:54:14 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/17 19:38:14 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"
#include <stdarg.h>
#include <unistd.h>

static void write_digits(char const *format, va_list args, int *count)
{
	if (*format == 'c')
		ch_format(args, count);
	/*if (*format == 's')
		str_format();
	if (*format == 'p')
		ptr_format();
	if (*format == 'd')
		double_format();
	if (*format == 'i')
		i_format();
	if (*format == 'u')
		u_format();
	if (*format == 'x')
		x_format();
	if (*format == 'X')
		X_format();
	if (*format == '%')
	{

	}*/
}

int ft_printf(char const *format, ...)
{
	int	i;
	int	count;
    va_list args;

	count = 0;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i++] != '\0')
		{
			write_digits(&format[i], args, &count);
			format++;
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	char	c = 'c';
	ft_printf("Hola mundo este es el resultado: %c", c);
}
