/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:04:37 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/22 12:55:22 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_str(va_list args, int *count)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		write(1, "(null)", 6);
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	(*count) += i;
}
