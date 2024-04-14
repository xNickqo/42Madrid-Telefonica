/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:24:12 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/14 21:51:25 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

/*Comprueba si el caracter es alfanumerico.
 * Devuelve 1 si el caracter es alfanumerico y 0 si NO es alfanumerico*/

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c = 'a';
	if (ft_isalnum(c))
		printf("%c es alfanumerico\n", c);
	else
		printf("%c no es alfanumerico\n", c);

	int	res = ft_isalnum(c);
	printf("El resultado de mi funcion es: %d\n", res);


	char    x = 'a';
	if (isalnum(x))	
		printf("%c es alfanumerico\n", x);
	else
		printf("%c no es alfanumerico\n", x);

	int     reso = isalnum(c);
	printf("El resultado de mi funcion es: %d\n", reso);
}*/
