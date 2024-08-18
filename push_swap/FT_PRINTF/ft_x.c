/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:05:09 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/24 17:36:44 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

void	ft_x(va_list args, int *count)
{
	unsigned int	n;
	char			*str;
	int				len;

	n = va_arg(args, unsigned int);
	str = ft_uitoa_hex(n, 0);
	len = ft_strlen(str);
	if (str)
	{
		write(1, str, len);
		(*count) += len;
		free(str);
	}
}
