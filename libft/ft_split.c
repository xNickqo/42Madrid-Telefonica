/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:59:04 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/29 14:59:10 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

#include <string.h>

/*Reserva utilizando malloc() un array de strings resultante de 
 * separar la string 's' en substrings utilizando el caracter "c"
 * como delimitador. El array debe termianr con un puntero NULL
 *
 * Debe devolver un array de nuevas strings resultante de la 
 * separacion y NULL si falla la reserva de memoria.*/

char	**ft_split(char const *s, char c)
{
	
}

int	main(void)
{
	char	s[] = "Hello, World, This, is, an, Example";
	const char c = ",";

	char **res = ft_split(s, c);

	int i = 0;
	while (res[i] != NULL)
	{
		printf("%s\n", res[i]);
		i++;
	}
	//Output
	//Hello
	//world
	//this
	//is
	//an
	//example
}
