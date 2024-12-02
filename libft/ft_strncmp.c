/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:39:57 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/24 16:51:08 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/* Comparar los primeros n caracteres de dos cadenas de caracteres 
 * null-terminadas. Devuelve un valor entero que indica la relación entre 
 * las cadenas: un valor negativo si la primera cadena es menor 
 * que la segunda, cero si son iguales hasta los primeros n caracteres, 
 * o un valor positivo si la primera cadena es mayor que la segunda. 
 *
 * Es útil cuando se quiere comparar solo una parte de las cadenas 
 * o cuando se quiere evitar desbordamientos de búfer al comparar 
 * cadenas de longitud desconocida.*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/* 
int	main(void)
{
	char s1[100] = "abc";
	char s2[] = "aba";
	int x = ft_strncmp(s1, s2, 8);
	printf("%d", x);
}
 */