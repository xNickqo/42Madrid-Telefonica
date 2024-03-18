/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:33:10 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/19 11:39:21 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * strcmp() es una funcion que compara 2 cadenas y devuelve un numero
 * nº positivo si s1 > s2
 * nº negativo si s1 < s2
 * 0 si las dos cadenas son iguales
 *
 * pero no compara la longitud entre cadenas, sino el ascii del primer
 * caracter que las diferencia
 * Por ejemplo:
 * a = "hola"
 * b = "holo"
 *
 * El primer caracter que diferrencia las cadenas es el 4º
 * a = 97	b = 111 	a - b = resultado
 */
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
int	main(void)
{
	char s1[] = "hola";
	char s2[] = "holo";
	int x = ft_strcmp(s1, s2);
	printf("%d", x);
}*/
