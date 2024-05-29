/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:25:37 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/17 17:09:10 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*int	main(void){
	char a[] = "hola mundo";
	char b[] = "manuel";
	ft_strncpy(a, b, 6);
}*/
/*primero creo una variable para recorrer los caracteres
mientras que esa variable sea menor que n y no encuentre
un caracter null, sustituye los caracteres, i++ y sigue 
recorriendo mientras se cumpla la condicion.

Despues mientras que la i sea menor que la n,
añade caracteres null */
