/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:04:37 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/19 15:33:57 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libftprint.h"

void	str_format(va_list args, int *count)
{
	char	*str;
	int	i;
	
	i = 0;
	str = va_arg(args, char *);
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	(*count)++;
}
