/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:58:11 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/04 19:39:11 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quick_sort(t_list **a, t_list **b)
{
    t_list *pivot_node;
    int 	pivot_value;

	printlst(*a, *b);

    pivot_node = ft_lstlast(*a);
    pivot_value = pivot_node->value;
    printf("Pivote: %i\n", pivot_value);

	int	i = 0;
	while (i < ft_lstsize(*a))
	{
		if ((*a)->value > pivot_value)
			pb(a, b);
		else
			ra(a);
		
		i++;
	}
	
    printlst(*a, *b);
}



