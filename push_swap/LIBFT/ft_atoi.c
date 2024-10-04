/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:29:01 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/04 18:43:21 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*Convierte una cadena de caracteres(numeros) en int*/

int	ft_atoi(const char *str)
{
	int	resultado;
	int	signo;

	signo = 1;
	resultado = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signo = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		resultado = resultado * 10 + (*str - '0');
		str++;
	}
	return (resultado * signo);
}
/*
int	main(void)
{
	char	a[] = "-2147483648";
	int	num;

	num = ft_atoi(a);
	printf("%d", num);
}*/
/*
	char	c = '3';
	//	Whitespaces in C
	// ' ', '\n', '\t', '\v', '\f', '\r' 
	if (isspace(c))
	{
		printf("'%c' es un espaciado. \n", c);
	}
	else
	{
		printf("'%c' NO ES UN ESPACIADO. \n", c);
	}
}
*/
