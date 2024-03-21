/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:12:16 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/21 16:13:50 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

/*La funcion toupper() convierte caracteres individuales en MINUSCULAS*/

int	ft_tolower(int c)
{
	if (c >= 'a' && c <= 'z')
		c += 32;
	return (c);
}
/*
int	main(void)
{
	//Mi funcion
	char c = 'a';
	int res = ft_tolower(c);
	printf("%c\n", res);

	//Funcion original
	char co = 'a';
	int reso = tolower(co);
	printf("%c\n", reso);
}*/
