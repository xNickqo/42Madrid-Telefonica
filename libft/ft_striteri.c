/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:22:47 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/01 21:16:02 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/*A cada carácter de la string ’s’, aplica la función
 * ’f’ dando como parámetros el índice de cada
 * carácter dentro de ’s’ y la dirección del propio
 * carácter, que podrá modificarse si es necesario.*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	
	if (s == NULL || f == NULL)
		return (NULL);

	i = 0;
	while (s[i] != '\0')
	{
		f(index, &s[i]);
		i+;
			i+;
	}
}
