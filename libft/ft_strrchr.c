/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:08:42 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/21 17:23:12 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*La funcion strrchr() es identica a strchr(), solo que devolviendo un puntero
 * a la ultima ocurrencia del caracter c en la cadena s*/

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*last_ocurrence;

	i = 0;
	last_ocurrence = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			last_ocurrence = (char *)&str[i];
		i++;
	}
	if (c == '\0')
		return ((char *)str + i);
	return (last_ocurrence);
}
