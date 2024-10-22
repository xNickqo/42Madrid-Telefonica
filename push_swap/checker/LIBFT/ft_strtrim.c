/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:59:24 by niclopez          #+#    #+#             */
/*   Updated: 2024/05/07 16:25:39 by niclopez         ###   ########.fr       */
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
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trim = (char *)malloc(end - start + 1);
	if (!trim)
		return (0);
	i = start;
	while (i < end)
	{
		trim[i - start] = s1[i];
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
