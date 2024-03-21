/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:29:39 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/21 16:11:52 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

/*La funcion toupper() convierte caracteres individuales en mayusculas
 *
 * No convierte cadenas de strings, para ello necesitas iterar sobre cada 
 * caracter de la cadena y aplicar la funcion. Por ejemplo:
 * 
 * while(i < strlen(str))
 * {
 * 		str[i] = toupper(str[i]);
 * 		i++;
 * }
 * */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	//Mi funcion
	char c = 'a';
	int res = ft_toupper(c);
	printf("%c\n", res);

	//Funcion original
	char co = 'a';
	int reso = toupper(co);
	printf("%c\n", reso);
}*/
