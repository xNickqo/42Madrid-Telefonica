/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:54:14 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/13 20:08:14 by niclopez         ###   ########.fr       */
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
		ft_xupper(args, count);
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

/* int main(void)
{
	char char1 = 'a';
	int	c = 0;
	int min = -48;
	char *str = "";
	char *ptr = "Hola Mundo";
	unsigned int u = 42;
	int x = 108042;

	//c s p i d u x X % pruebas
	ft_printf("Hola mundo\n");
	ft_printf("%c\n", char1);
	ft_printf("%s\n", str);
	ft_printf("%p\n", ptr);
	ft_printf("%d, %i\n", c, min);
	ft_printf("%u\n", u);
	ft_printf("%x\n", x);
	ft_printf("%%\n");

	ft_printf("\n-----------------------------\n");

	printf("Hola mundo\n");
	printf("%c\n", char1);
	printf("%s\n", str);
	printf("%p\n", ptr);
	printf("%d, %i\n", c, min);
	printf("%u\n", u);
	printf("%x\n", x);
	printf("%%\n");
} */
