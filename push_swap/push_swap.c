/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:55:27 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/05 20:07:12 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Crea una lista e introduce los valores dentro*/
void init_values(t_list *stack, int value)
{
    t_list  *new_node;

    new_node = ft_lstnew(value);
    if (new_node)
        ft_lstadd_front(*stack->index, new_node);
}

/*Libera la memoria de reservada de una pila*/
void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

