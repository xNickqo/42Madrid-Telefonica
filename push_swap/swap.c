/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:10:24 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/01 20:16:26 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a) : si hay 2 números, intercambia los primeros 2 elementos en la 
	parte superior de la pila a.

sb (swap b) : si hay 2 números, intercambia los primeros 2 elementos en la 
	parte superior de la pila b.

ss : sa y sb al mismo tiempo.
*/

int	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*lst) < 2)
		return (-1);
	first = *lst;
	second = first->next;
	tmp_val = first->value;
	tmp_index = first->index;
	first->value = second->value;
	first->index = second->index;
	second->value = tmp_val;
	second->index = tmp_index;
	return (0);
}

int	sa(t_list **a)
{
	if (swap(a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **b)
{
	if (swap(b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
	return (0);
}