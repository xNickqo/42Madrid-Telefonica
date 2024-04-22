/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:23:09 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/22 16:26:12 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

void	ft_char(va_list args, int *count)
{
	char	c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	(*count)++;
}
