/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:06:19 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/31 21:59:06 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/*La funcion memcmp() n bytes de los strings s1 y s2 sin tener en cuenta la
 *  * terminacion nula, esa es la principal diferencia entre esta funcion y
 *   * strncmp()*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp1;
	const unsigned char	*temp2;
	size_t				i;

	temp1 = s1;
	temp2 = s2;
	i = 0;
	while (i < n)
	{
		if (temp1[i] != temp2[i])
			return (temp1[i] - temp2[i]);
		i++;
	}
	return (0);
}
/*
 * int     main(void)
 * {
 *         char str1[] = "Hello";
 *         char str2[] = "Hello";
 *         char str3[] = "Hellow";
 *         char str4[] = "Hola";
 *
 *         int res = ft_memcmp(str1, str4, 6);
 *         printf("%d\n", res);
 *
 *         int reso = memcmp(str1, str4, 6);
 *         printf("%d\n", reso);
 *}*/
