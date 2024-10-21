/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:09:40 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/21 17:14:38 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Libera la memoria de reservada de una pila*/
void	free_stacks(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (a == NULL && b == NULL)
		return ;
	if (a != NULL)
	{
		while (*a)
		{
			tmp = *a;
			*a = (*a)->next;
			free(tmp);
		}
		*a = NULL;
	}
	if (b != NULL)
	{
		while (*b)
		{
			tmp = *b;
			*b = (*b)->next;
			free(tmp);
		}
		*b = NULL;
	}
}

void	ft_error(char *message, t_list **a, t_list **b)
{
	ft_putendl_fd(message, 2);
	free_stacks(a, b);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
