/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:11:39 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/01 20:15:07 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ra (rotar a) : desplaza todos los elementos de la pila a una posición 
	hacia arriba. El primer elemento se convierte en el último.

rb (rotar b) : desplaza todos los elementos de la pila b una posición
	hacia arriba. El primer elemento se convierte en el último.

rr : ra y rb al mismo tiempo.
*/

int	rotate(t_list **lst)
{
	t_list	*list;
	t_list	*last;

	if (ft_lstsize(*lst) < 2)
		return (-1);
	list = *lst;
	last = ft_lstlast(list);
	*lst = list->next;
	list->next = NULL;
	last->next = list;
	return (0);
}

int	ra(t_list **a)
{
	if (rotate(a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **b)
{
	if (rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
	return (0);
}