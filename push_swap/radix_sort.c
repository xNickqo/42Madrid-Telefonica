/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:58:11 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/21 20:51:02 by niclopez         ###   ########.fr       */
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
	t_list	*current;
	t_list	*runner;
	int		index;

	current = *lst;
	while (current)
	{
		index = 0;
		runner = *lst;
		while (runner)
		{
			if (runner->value < current->value)
				index++;
			runner = runner->next;
		}
		current->index = index;
		current = current->next;
	}
}

/* 
   Calcula cuántos bits son necesarios para representar el índice más
   grande en la lista.
*/
int	get_max_bits(t_list **lst)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *lst;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/* 
   Procesa los elementos de la lista bit a bit, verificando el bit `i`
   de cada índice. Si el bit `i` es 1, rota el elemento en la lista 'a',
   si es 0, lo mueve a la lista 'b'.
*/
void	process_bits(t_list **a, t_list **b, int i, int size)
{
	t_list	*head_a;
	int		j;

	j = 0;
	while (j++ < size)
	{
		head_a = *a;
		if (((head_a->index >> i) & 1) == 1)
			ra(a);
		else
			pb(a, b);
	}
}

/* 
   Implementa el algoritmo de ordenación Radix Sort. Asigna índices
   a los elementos de la lista, calcula el número máximo de bits necesarios,
   y procesa los bits uno por uno, moviendo elementos entre las listas 'a' y 'b'.

   github explicacion: https://github.com/42YerevanProjects/push_swap/tree/master
*/
void	radix_sort(t_list **a, t_list **b)
{
	t_list	*head_a;
	int		i;
	int		size;
	int		max_bits;

	assign_indexes(a);
	i = 0;
	head_a = *a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		process_bits(a, b, i, size);
		while (ft_lstsize(*b) != 0)
			pa(a, b);
		i++;
	}
}
