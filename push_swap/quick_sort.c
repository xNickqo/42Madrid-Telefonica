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

int	median_of_three(t_list **a)
{
	t_list	*current;
	int		size;
	int		median_index;
	int		first_median;
	int		second_median;
	int		*values;
	int		i;
	int		median;

	current = *a;
	size = ft_lstsize(current);
	median_index = size / 2;
	first_median = 0;
	second_median = 0;
	values = malloc(size * sizeof(int));
	i = 0;
	//Llena el array con los valores de la lista
	while (current != NULL)
	{
		values[i++] = current->value;
		current = current->next;
	}
	if (size / 2 == 0)
	{
		first_median = values[median_index - 1];
		second_median = values[median_index];
		free(values);
		return (first_median + second_median) / 2;
	}
	else
	{
		median = values[median_index];
		free(values);
		return (median);
	}
}

void quick_sort(t_list **a, t_list **b)
{
    int 	pivot;

	printlst(*a, *b);

    pivot = median_of_three(a);

    printf("Pivote: %i\n", pivot);

	int	i = 0;
	int	initial_size = ft_lstsize(*a);
	while (i < initial_size)
	{
		if ((*a)->value > pivot)
			pb(a, b);
		else
			ra(a);
		
		i++;
	}
	
    printlst(*a, *b);
}



