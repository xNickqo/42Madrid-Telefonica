/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:21:41 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/15 18:36:12 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La funcion strcpy() copia la cadena de caracteres apuntada
 * por *src(incluyendo el caracter terminador'\0') al vector apuntado 
 * por *dest Las cadenasno deben solaparse, y la de destino debe ser
 * lo suficientemente grande como para alojar la copia
 *
 * La funcion devuelve un puntero a la cadena de destino *src
 * */

#include <stdio.h>

char	*ft_strcpy(char	*dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (temp);
}
/*
int 	main(void){
	char hola[] = "hola mundo";
	char adios[30] = "adios";
	ft_strcpy(hola, adios);
	printf("%s", hola);
}*/
