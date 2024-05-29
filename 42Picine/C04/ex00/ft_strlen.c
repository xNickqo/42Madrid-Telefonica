/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:06:56 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/21 17:49:00 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	str[] = "hola me llamo nico y esta este es el ex00";

	int	x;
	x = strlen(str);
	printf("strlen()    : %d \n", x);

	int y;
	y = ft_strlen(str);
	printf("ft_strlen() : %d ", y);
}*/
