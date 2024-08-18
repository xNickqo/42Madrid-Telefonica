/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:07:16 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/14 21:50:07 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include "libft.h"

/*Comprueba si el caracter es alfabetico 
 * si lo es, devuelve 1, si no devuelve 0*/

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int	main(void)
{
	int c = 'A';
	if(ft_isalpha(c))
		printf("%d es alpha", c);
	else
		printf("%d no es alpha", c);
}*/
