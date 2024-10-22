/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:58:11 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/22 19:53:53 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
   Asigna índices a los elementos de la lista en función de su valor.
   Para cada elemento, cuenta cuántos valores en la lista son menores
   y usa ese conteo como índice.
*/
void	assign_indexes(t_list **lst)
{
	t_list	*tmp;
	t_list	*runner;
	int		index;

	tmp = *lst;
	while (tmp)
	{
		index = 0;
		runner = *lst;
		while (runner)
		{
			if (runner->value < tmp->value)
				index++;
			runner = runner->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}

/* 
   Calcula cuántos bits son necesarios para representar el índice más
   grande en la lista. Por ejemplo:
		0 -> 000
		1 -> 001
		2 -> 010
		3 -> 011
		4 -> 100
		5 -> 101
	Si el indice mas grande es el 5, se necesitaran 3bits
*/
int	get_max_bits(t_list **lst)
{
	t_list	*tmp;
	int		max;
	int		max_bits;

	tmp = *lst;
	max = tmp->index;
	max_bits = 0;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/* 
   Procesa los elementos de la lista bit a bit, verificando el bit `i`
   de cada índice. Si el bit `i` es 1, rota el elemento en la lista 'a',
   si es 0, lo mueve a la lista 'b'. De ta manera que los elementos con el bit 1
   se mantendran en la lista 'a'.
   Por ejemplo:
		0 en binario: 000 → bit 0 = 0, pb
		1 en binario: 001 → bit 0 = 1, ra
		2 en binario: 010 → bit 0 = 0, pb
		3 en binario: 011 → bit 0 = 1, ra
		4 en binario: 100 → bit 0 = 0, pb
		5 en binario: 101 → bit 0 = 1, ra

	A: 1[1] -> 3[3] -> 5[5]
	B: -1[0] -> 2[2] -> 4[4]
*/
void	process_bits(t_list **a, t_list **b, int i, int size)
{
	t_list	*tmp;
	int		j;

	j = 0;
	while (j++ < size)
	{
		tmp = *a;
		if (((tmp->index >> i) & 1) == 1)
		{
			ra(a);
		}
		else
		{
			pb(a, b);
		}
	}
}

/* 
	1. Analiza los indices correctos de los numeros
	2. Obtenemos bit_max, es decir el numero con mas bits
	3. Mientras el indice del bit sea menor que el max_bits procesa los bits
		de esa posicion y mueve todo a la lista A y asi reiteradamente cambiando
		de posicion de bit, es decir, primero con 0 luego 100, luego 1000...

   	github explicacion: https://github.com/42YerevanProjects/push_swap/tree/master
*/
void	radix_sort(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		i;
	int		size;
	int		max_bits;

	assign_indexes(a);
	i = 0;
	tmp = *a;
	size = ft_lstsize(tmp);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		process_bits(a, b, i, size);
		while (ft_lstsize(*b) != 0)
		{
			pa(a, b);
		}
		i++;
	}
}
