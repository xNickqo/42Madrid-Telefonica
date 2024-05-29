/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:31:36 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/21 22:21:57 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Primero creo 2 variables para las cada grupo de X (XX XX). 
 * acto seguido hago una iteracion tanto de a como de b
 * cuando estos numeros cumplan la condicion se ira sumando 1 numero mas, 
 * Despues convertir los char a digitos el c[0] 
 * captura el primer digito de cada letra y c[2] el segundo digito
 * */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c[2];

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			c[0] = a / 10 + '0';
			c[1] = a % 10 + '0';
			write(1, &c, 2);
			write(1, " ", 1);
			c[0] = b / 10 + '0';
			c[1] = b % 10 + '0';
			write(1, &c, 2);
			write(1, ",", 1);
			write(1, " ", 1);
			b++;
		}
		a++;
	}
}
