/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:03:01 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/22 15:44:18 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprint.h"
#include <stdarg.h>

void	ft_int(va_list args, int *count)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg(args, int);
	str = ft_itoa(n);
	len = ft_strlen(str);
	if (str)
	{
		write(1, str, len);
		count += len;
		free(str);
	}
}
