/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:31:37 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/11 22:42:53 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Cada variable char sera un digito
 * Se inicializa i como '0' 
 * 
 * En los bucles while se inicializa i<=7 j<=8 y k<=9 para 
 * garantizar que no exceda los limites de un solo digito 
 *
 * Cada vez que se ejecute un bucle se sumara 1 al sig digito
 *
 * Se imprimen todos los digitos seguidos
 *
 * La coma solo se pondra si el numero es distinto de 789
 * que es el ultimo
 *
 * Con cada iteracion se sumara 1 digito hasta llegar al 
 * limite eestablecido en la condicion de cada while.
 * */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				write(1, &i, 1);
				write(1, &j, 1);
				write(1, &k, 1);
				if (!(i == '7' && j == '8' && k == '9'))
					write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
}
