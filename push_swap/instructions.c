/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:53:02 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/14 20:13:40 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Intercambia los primeros elementos entre la lista A y la B */
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

/* Coje el primer elemento de 'src' y l pone en 'dest' */
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

/* Rota los elementos a de la lista 1 valor hacia la derecha y el ultimo valor se vuelve
	el primero*/
int rotate(t_list **lst)
{
    t_list *list;
    t_list *last;

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


/* Al contrario que con rotate */
int	reverseRotate(t_list **lst)
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
	if (reverseRotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **b)
{
	if (reverseRotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	reverseRotate(a);
	reverseRotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}