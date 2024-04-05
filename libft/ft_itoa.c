/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:33:46 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/05 21:00:14 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>

/*Esta funcion convierte un numero en un string reservando memoria con 
 * malloc()*/

static unsigned int	number_len(int temp)
{
	unsigned int	len;

	len = 0;
	if (temp <= 0)
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

char	*ft_itoa(int n)
{
	char	*res;
	unsigned int	len;
	unsigned long	temp;

	len = number_len(n);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	temp = 0;
	if (n < 0)
		temp = -(long)n;
	else
		temp = n;
	while (len > 0)
	{
		res[--len] = '0' + (temp % 10);
		temp /= 10;
	}
	if (n < 0 && len == 0)
		res[0] = '-';
	return (res);
}
/*
int	main(void)
{
	char	*res;
	res = ft_itoa(-10004);
	printf("%s\n", res);
}*/
