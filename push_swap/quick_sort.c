/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:58:11 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/15 20:07:51 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para obtener el pivote como la media entre el valor mínimo y máximo
int get_pivot(t_list **a)
{ 
    t_list	*tmp;
    int		min_value;
    int		max_value;

    tmp = *a;
    min_value = tmp->value;
    max_value = tmp->value;
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

// Calcula si es más eficiente hacer rotate o reverse rotate
int is_closer_to_end(t_list **lst, t_list *target)
{
	int		size;
	int		pos;
	t_list	*tmp;

    // Encontrar la posición del nodo
	pos = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp == target)
			break ;
		tmp = tmp->next;
		pos++;
	}
	size = ft_lstsize(*lst);
    // Si el nodo está en la segunda mitad, es más eficiente usar reverse rotate
	return (pos > size / 2);
}

void move_to_top_a(t_list **a, t_list *target)
{
    if (is_closer_to_end(a, target))  // Si está más cerca del final, usamos rra
    {
        while (*a != target)
        {
            rra(a);
            /* printlst(*a, NULL); */
        }
    }
    else  // Si está más cerca del principio, usamos ra
    {
        while (*a != target)
        {
            ra(a);
            /* printlst(*a, NULL); */
        }
    }
}

void move_to_top_b(t_list **b, t_list *target)
{
    if (is_closer_to_end(b, target))  // Si está más cerca del final, usamos rrb
    {
        while (*b != target)
        {
            rrb(b);
            printlst(NULL, *b);
        }
    }
    else  // Si está más cerca del principio, usamos rb
    {
        while (*b != target)
        {
            rb(b);
            printlst(NULL, *b);
        }
    }
}

void sort_a(t_list **a)
{
    t_list *min_node = *a;
    t_list *current = min_node->next;
    
    if (ft_lstsize(*a) < 2)
        return;
    while (current)
    {
        if (current->value < min_node->value)
            min_node = current;
        current = current->next;
        printlst(*a, NULL);
    }
    move_to_top_a(a, min_node);
    sort_a(&(*a)->next);
}

void sort_b(t_list **b)
{
    t_list *max_node = *b;
    t_list *current = max_node->next;
    
    if (ft_lstsize(*b) < 2)
        return ;
    while (current)
    {
        if (current->value > max_node->value)
            max_node = current;
        current = current->next;
        printlst(NULL, *b);
    }
    move_to_top_b(b, max_node);
    sort_b(&(*b)->next);
}


void quick_sort(t_list **a, t_list **b)
{
	ft_putendl_fd("\nLista desordeanda: ", 1);
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
            ra(a);
        }
        else
        {
            pb(a, b);
        }
        printlst(*a, *b);
        i++;
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
        printlst(*a, *b);
    }
	ft_putendl_fd("\nLista ordeanda: ", 1);
    printlst(*a, *b);
}
