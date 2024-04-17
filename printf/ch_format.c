/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:23:09 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/17 19:33:19 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"
#include <unistd.h>
#include <stdarg.h>

void	ch_format(va_list args, int *count)
{
	char	c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	(*count)++;
}
