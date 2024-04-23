/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:54:14 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/23 15:12:45 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static void	write_digits(char const *format, va_list args, int *count)
{
	if (*format == 'c')
		ft_char(args, count);
	if (*format == 's')
		ft_str(args, count);
	if (*format == 'p')
		ft_ptr(args, count);
	if (*format == 'i' || *format == 'd')
		ft_int(args, count);
	if (*format == 'u')
		ft_unsignedint(args, count);
	if (*format == 'x')
		ft_x(args, count);
	if (*format == 'X')
		ft_X(args, count);
	if (*format == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			write_digits(&format[i], args, &count);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main(void)
{
	int		num = 4542;
	char	c = 'c';
	char	*str = "Hola mundo";
	void	*ptr = &num;

	ft_printf(" char: %c \n str: %s \n ptr: %p \n int: %i \n u: %u\n x en hex: %x\n", c, str, ptr, num, num, num);

	ft_printf("\n-----------------------------\n");

	printf(" char: %c\n str: %s \n ptr: %p \n int: %i \n u: %u\n x en hex: %x\n", c, str, ptr, num, num, num);
}*/
