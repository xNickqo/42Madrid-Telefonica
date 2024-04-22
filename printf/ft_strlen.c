/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:24:36 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/22 15:42:33 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libftprint.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
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
