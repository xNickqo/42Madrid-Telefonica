/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:50:19 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/14 21:50:55 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

/*Comprueba si el caracter es ASCII
 * Devuelve 1 si lo es, 0 si no lo es*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c = 'a';
	if (ft_isascii(c))
		printf("%c es un caracter ascci\n", c);
	else
		printf("%c No\n", c);
	int 	res = ft_isascii(c);
	printf("Resultado entero de mi funcion = %d\n", res);

	
	char	x = 'a';
	if (isascii(x))
		printf("%c es un caracter ascci\n", x);
	else
		printf("%c No\n", x);
	int     reso = isascii(x);
	printf("Resultado entero de mi funcion = %d\n", reso);

}*/
