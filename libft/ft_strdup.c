/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:38:50 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/31 21:55:50 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*La funcion strdup() reserva espacio de almacenamiento para una copia de
 * serie llamando a malloc. Se espera que el argumento de serie para esta
 * funcion contenga un caracter '\0' que marque el final de la serie.
 * Recordar liberar con free() */

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(str) + 1;
	dest = (char *)malloc(len);
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, str, len);
	return (dest);
}
/*
int	main(void)
{
	char	*str = "HelloWorld!";

	//Mi funcion
	char	*reso = ft_strdup(str);
	printf("%s\n", reso);


	//Funcion original
	char	*res = strdup(str);
	printf("%s\n", res);
}*/
