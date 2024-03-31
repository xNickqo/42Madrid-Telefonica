/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:00:57 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/31 21:52:49 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*Esta funcion sirve para extraer partes especificas de un string 
 * en funcion de su indice de inicio y su longitud especidificada*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	s_len;
	char	*sub;

	s_len = ft_strlen(s);
	if (s == '\0')
		return (0);
	if (start >= s_len)
		return (0);
	sub_len = len;
	(char *)malloc(s_len + 1);
	if (sub == '\0')
		return (0);
	ft_memcpy(sub, s + start, sub_len);
	sub[sub_len] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char	*original = "Nico es guapo y perni tambien";
	unsigned int start = 8;
	size_t len = 5;

	char *sub = ft_substr(original, start, len);
	if (sub != NULL)
	{
		printf("Subcadena : %s\n", sub);
		free(sub);
	}else{
		printf("Error");
	}
}*/