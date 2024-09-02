/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:55:27 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/02 19:06:08 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Crea una lista e introduce los valores dentro*/
void push(t_stack *stack, int value)
{
    t_node  *new_node = (t_node *)malloc(sizeof(t_node));
    
    new_node->value = value;
    new_node->next = stack->last;
    stack->last = new_node;
}

/*Libera la memoria de reservada de una pila*/
void    free_stack(t_stack *stack)
{
    t_node  *current = stack->last;
    t_node  *next_node;

    while(current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    stack->last = NULL;

}

/*Intercambia los dos primeros elementos de la pila 'stack'*/
/*sa, sb, ss*/
void    s(t_stack *stack)
{
    if (stack->last && stack->last->next)
    {
        t_node *first = stack->last;
        t_node *second = stack->last->next;

        first->next = second->next;
        second->next = first;
        stack->last = second;
    }
}

/*Mueve el elemento superior de la pila 'src' a la pila 'dest'*/
void    p(t_stack *src, t_stack *dest)
{
    if (src->last)
    {
        t_node *tmp = src->last;
        src->last = src->last->next;

        tmp->next = dest->last;
        dest->last = tmp;
    }
}

/*Mueve todos los elementos de la pila 'stack' una posicion hacia arriba y 
el primer elemento se mueve al final*/
void    r(t_stack *stack)
{
    if (stack->last && stack->last->next)
    {
        t_node *first = stack->last;
        t_node *current = stack->last;

        while (current->next != NULL)
            current = current->next;

        current->next = first;
        first->next = NULL;
    }
}

/*Mueve todos los elementos de la pila 'stack' una posicion hacia abajo y 
el ultimo elemento se mueve al principio*/
void rr(t_stack *stack)
{
    if (stack->last && stack->last->next)
    {
        t_node *current = stack->last;
        t_node *prev = NULL;

        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        current->next = stack->last;
        stack->last = current;
    }
}
