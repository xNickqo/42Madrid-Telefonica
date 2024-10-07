/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:58:11 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/07 20:08:53 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para obtener el pivote como la media entre el valor mínimo y máximo
int get_pivot(t_list **a)
{ 
    t_list *tmp = *a;
    int min_value = tmp->value;
    int max_value = tmp->value;

    while (tmp)
    {
        if (tmp->value < min_value)
            min_value = tmp->value;
        if (tmp->value > max_value)
            max_value = tmp->value;
        tmp = tmp->next;
    }
    return (min_value + max_value) / 2;
}

void quick_sort(t_list **a, t_list **b)
{
    printlst(*a, *b);

    int pivot = get_pivot(a);
    printf("Pivote: %i\n", pivot);

    int size = ft_lstsize(*a);
    int i = 0;
    while (i < size)
    {
        t_list *current = *a;

        if (current->value > pivot)
        {
            pb(a, b);
        }
        else
        {
            ra(a);
        }
		i++;
    }

    printlst(*a, *b);
}
