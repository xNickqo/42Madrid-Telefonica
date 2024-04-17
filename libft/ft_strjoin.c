/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:59:43 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/03 18:06:06 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*Reserva con malloc() y devuelve una nueva string, formada por la
 * concatenacion de s1 y s2*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == '\0')
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	res[ft_strlen(s1) + i] = '\0';
	return (res);
}
/*
int	main(void)
{
	char	*s1 = NULL;
	char	*s2 = NULL;
	char	*res = ft_strjoin(s1, s2);
	printf("%s\n", res);
}*/