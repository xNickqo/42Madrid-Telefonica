/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:11:05 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/22 18:04:38 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include <unistd.h>

static unsigned int	number_len(unsigned int temp)
{
	unsigned long	len;
	unsigned long	n;

	n = (unsigned long)temp;
	len = 0;
	if (temp == 0)
		len = 1;
	else
		len = 0;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char			*res;
	unsigned int	len;
	unsigned long	temp;

	len = number_len(n);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	temp = n;
	while (len > 0)
	{
		res[--len] = '0' + (temp % 10);
		temp /= 10;
	}
	return (res);
}
