/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:41:56 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/21 16:56:05 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*La funcion memmove() copia n bytes de src -> dest
 *
 * Las areas de memoria pueden solaparse*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (0);
	if (d < s)
	{
		i = len;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	//MI FUNCION 
	char	src[] = "hello world";
	char	dest[] = "hola";

	printf("%s\n", dest);

	ft_memmove(dest, src, 5);

	printf("%s\n", dest);
}*/
