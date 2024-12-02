/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:38:50 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/24 16:51:23 by niclopez         ###   ########.fr       */
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
	char	*copy;

	len = ft_strlen(str) + 1;
	copy = (char *)malloc(len);
	if (copy == 0)
		return (0);
	ft_strlcpy(copy, str, len);
	return (copy);
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
