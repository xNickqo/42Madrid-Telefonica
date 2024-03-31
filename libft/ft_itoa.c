/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:33:46 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/31 22:02:29 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>

/*Esta funcion convierte un numero en un string reservando memoria con 
 * malloc()*/

char	*ft_itoa(int n)
{
	char	*res;
	int	len;
	int	signo;
	int	temp;

	temp = n;
	len = 1;
	while (temp /= 10)
		len++;
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	signo = 1;
	if (n < 0)
	{
		signo = -1;
		temp = -n;
		len++;
	}
	res[len] = '\0';
	while (len-- > 0)
	{
		res[len] = '0' + (n % 10) * signo;
		n /= 10;	
	}
	if (signo == -1)
		res[0] = '-';
	return (res);
}
/*
int	main(void)
{
	char	*res;
	res = ft_itoa(2147483648);
	printf("%s\n", res);
}*/
