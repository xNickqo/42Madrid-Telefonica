/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:12:34 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/01 20:14:23 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-----------------------------------------------------------------------------

rra (rotación inversa a) : desplaza todos los elementos de la pila una 
	posición hacia abajo. La pila a. El último elemento se convierte en el 
	primero.

rrb (rotación inversa b) : desplaza todos los elementos de la pila b una 
	posición hacia abajo. El último elemento se convierte en el primero.
	
rrr : rra y rrb al mismo tiempo 

-----------------------------------------------------------------------------*/

int	reverse_rotate(t_list **lst)
{
	t_list	*list;
	t_list	*prev;

	if (ft_lstsize(*lst) < 2)
		return (-1);
	list = *lst;
	prev = NULL;
	while (list->next != NULL)
	{
		prev = list;
		list = list->next;
	}
	prev->next = NULL;
	list->next = *lst;
	*lst = list;
	return (0);
}

int	rra(t_list **a)
{
	if (reverse_rotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **b)
{
	if (reverse_rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
