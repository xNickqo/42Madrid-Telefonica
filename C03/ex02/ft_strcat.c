/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:42:50 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/20 13:42:11 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La funcion strcat() une la cadena src a la cadna dest sobreescriviendo
 * el caracter '\0' al final de dest, y entonces añade un caracter null,
 * Las cadenas no deben solaparse, y la caena dest debe tener el suficiente 
 * espacio para el almacenar el resultado*/

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}
/*
int	main(void)
{
	char	a[100] = "Hello";
	char	b[] = "World";
	ft_strcat(a, b);
	printf("El destino es igual a : %s \n", a);
	printf("%s", b);
}*/
