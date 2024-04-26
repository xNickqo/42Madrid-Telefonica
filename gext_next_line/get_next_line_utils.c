/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:09:29 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/26 17:57:48 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

/*FUNCIONES DE AYUDA*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while ((i < destsize - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

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

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*my_realloc(char *ptr, int old_size, int new_size)
{
	char	*new_ptr;
	int		i;

	if(ptr == NULL)
		return ((char *)malloc(new_size));
	new_ptr = (char *)malloc(new_size);
	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	i = 0;
	while (i < old_size)
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}
