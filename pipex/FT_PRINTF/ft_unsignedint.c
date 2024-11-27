/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:31 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/22 17:54:19 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdarg.h>

void	ft_unsignedint(va_list args, int *count)
{
	unsigned int	n;
	char			*str;
	int				len;

	n = va_arg(args, unsigned int);
	str = ft_uitoa(n);
	len = ft_strlen(str);
	if (str)
	{
		write(1, str, len);
		(*count) += len;
		free(str);
	}
}
