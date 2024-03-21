/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:49:13 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/21 15:22:04 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char c = 'a';
	if (ft_isdigit(c))
		printf("%c es un digito \n",c);
	else
		printf("%c no es un digito\n", c);
	
	int res = ft_isdigit(c);
	printf("Resultado de mi funcion: %d\n", res);


	char x = 'a';
	if (isdigit(x))
                printf("%c es un digito \n",x);
	else
		printf("%c no es un digito\n", x);
		
	int resoriginal = isdigit(x);
	printf("Resultado de la funcion original: %d\n", resoriginal);

}*/
