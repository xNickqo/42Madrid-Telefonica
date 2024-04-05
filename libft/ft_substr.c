/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:00:57 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/05 18:13:00 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*Esta funcion sirve para extraer partes especificas de un string 
 * en funcion de su indice de inicio y su longitud especidificada*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub;

	if (s == NULL)
		return (NULL);

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;

	sub = (char *)malloc(s_len * sizeof(char) + 1);
	if (sub == NULL)
		return (NULL);

	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
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
