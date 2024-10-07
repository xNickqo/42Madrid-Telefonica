/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:58:11 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/07 22:26:22 by niclopez         ###   ########.fr       */
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

void sort_a(t_list **a)
{
    int size = ft_lstsize(*a);
    int i;

    // Si la lista A tiene menos de 2 elementos, no es necesario ordenar
    if (size < 2)
        return;

    // Utiliza la selección para ordenar la lista
	i = 0;
    while (i < size)
    {
        t_list *min_node = *a;
        t_list *current = min_node->next;
        
        // Encontrar el nodo con el valor mínimo
        while (current)
        {
            if (current->value < min_node->value)
                min_node = current;
            current = current->next;
        }

        // Llevar el nodo mínimo a la parte superior de la lista
        if (min_node != *a)
        {
            while (*a != min_node)
                ra(a);
            // Después de llevar el mínimo al frente, ordena el resto
            sort_a(&(*a)->next);
        }
		i++;
    }
}

void sort_b(t_list **b)
{
    int size = ft_lstsize(*b);
    int i;

    // Si la lista B tiene menos de 2 elementos, no es necesario ordenar
    if (size < 2)
        return;

    // Utiliza la selección para ordenar la lista
	i = 0;
    while (i < size)
    {
        t_list *max_node = *b;
        t_list *current = max_node->next;

        // Encontrar el nodo con el valor máximo
        while (current)
        {
            if (current->value > max_node->value)
                max_node = current;
            current = current->next;
        }

        // Llevar el nodo máximo a la parte superior de la lista
        if (max_node != *b)
        {
            while (*b != max_node)
                rb(b);
            // Después de llevar el máximo al frente, ordena el resto
            sort_b(&(*b)->next);
        }
		i++;
    }
}

void quick_sort(t_list **a, t_list **b)
{
	ft_putendl_fd("\nLista desordeanda: ", 1);
    printlst(*a, *b);

	//Particion de las listas dependiendo del pivote
    int pivot = get_pivot(a);
    printf("Pivote: %i\n", pivot);

    int size = ft_lstsize(*a);
    int i = 0;
    while (i < size)
    {
        t_list *current = *a;

        if (current->value < pivot)
        {
            ra(a);
			i++;
        }
        else
        {
            pb(a, b);
        }
    }
	ft_putendl_fd("\nLista dividida: ", 1);
	printlst(*a, *b);

	//Ordenamos ambas listas
	sort_a(a);
	sort_b(b);
	ft_putendl_fd("\nLista dividida y ordenada: ", 1);
	printlst(*a, *b);

	//Pasamos todos los valores a la lista A
    while (ft_lstsize(*b) > 0)
    {
        pa(a, b);
    }
	ft_putendl_fd("\nLista ordeanda: ", 1);
    printlst(*a, *b);
}
