/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:09:07 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/21 16:59:26 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa (push a) : si b no está vacío, toma el primer elemento encima de b 
	y lo coloca en a.

pb (push b) : si a no está vacío, toma el primer elemento encima de a 
	y lo coloca en b.
*/

int	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (ft_lstsize(*src) == 0)
		return (-1);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	return (0);
}

int	pa(t_list **a, t_list **b)
{
	if (push(b, a) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
