/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:59:42 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/21 17:13:58 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Obtiene la poscion del numero mas pequeño de la lista*/
int	get_min_pos(t_list *a)
{
	t_list	*tmp;
	int		min_value;
	int		min_pos;
	int		i;

	tmp = a;
	min_value = tmp->value;
	min_pos = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->value < min_value)
		{
			min_value = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

/* 	
	Mueve el valor a la parte superior de la pila a usando 
	las operaciones 'ra' o 'rra', dependiendo de que tan cerca 
	este de la parte superior o inferior de la pila.
*/
void	move_to_top(t_list **a, int pos)
{
	int	size;
	int	i;

	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		i = 0;
		while (i < pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - pos)
		{
			rra(a);
			i++;
		}
	}
}

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third && first > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

/* Esta funcion maneja los casos de cuando tienes 2 o 3 elementos 'a'*/
void	small_sort(t_list **a)
{
	if (is_sorted(*a))
		return ;
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (ft_lstsize(*a) == 3)
	{
		sort_three(a);
	}
}

/*	
	Listas pequeñas entre 5 y 2 elementos 
	Identidicar el numero mas pequeño y colocarlo en la pila 'b', luego 
	continuar con el resto hasta que 'a' este ordenado. y pasar los 
	elementos de 'b' a 'a'
*/
void	simple_sort(t_list **a, t_list **b)
{
	int	min;

	while (ft_lstsize(*a) > 3)
	{
		min = get_min_pos(*a);
		move_to_top(a, min);
		pb(a, b);
	}
	small_sort(a);
	while (ft_lstsize(*b) > 0)
	{
		pa(a, b);
	}
}
