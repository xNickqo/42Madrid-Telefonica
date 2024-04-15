/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:59:24 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/15 14:19:19 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*La funcion elimina todos los caracteres de la string "set"
 * desde el principio y desde el final de "s1", hasta encontrar
 * un caracter no perteneciente a "set". La string resultante
 * se devuelve con una reserva de malloc() */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trim;
	size_t	i;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trim = (char *)malloc(end - start + 1);
	if (!trim)
		return (0);
	i = 0;
	while (i < end)
	{
		trim[i] = s1[i];
		i++;
	}
	trim[end - start] = '\0';
	return (trim);
}
/*
int	main(void)
{
	char	*s1 = "hola, soy Nico, y voy a separar todo, con comas :)";
	char	*set = ",";
	char	*trim = ft_strtrim(s1, set);
	printf("Cadena original : %s\nCadena recortada : %s\n", s1, trim);
	free(trim);
}*/
