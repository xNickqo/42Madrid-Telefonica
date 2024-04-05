/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:12:16 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/03 16:49:14 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

/*La funcion toupper() convierte caracteres individuales en MINUSCULAS*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int	main(void)
{
	char	i = 'a';
    while (i <= 'z')
    {
        char	c = ft_tolower(i);
        write(1, &c, 1);
        i++;
    }	
}*/
