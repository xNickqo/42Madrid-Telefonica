/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:19:58 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/24 18:53:37 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	resultado;
	int	signo;

	signo = 1;
	resultado = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			signo *= -1;
		}
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
	char	a[] = "   ---+--+1234ab567";
	int	num;

	num = ft_atoi(a);
	printf("%d", num);*/
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
