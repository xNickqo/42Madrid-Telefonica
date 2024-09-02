/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:13:16 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/02 23:42:02 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*Crea un nuevo nodo en la lista con malloc()

    La variable miembro 'content' se inicializa
    con el contenido del parametro 'content'. La
    variable 'next' con NULL*/

t_lst	*ft_lstnew(int value)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

/*Añade el nodo 'new' al principio de la lista 'lst'*/

void	ft_lstadd_front(t_lst **lst, t_lst *new)
{
    if (lst && new)
    {
        new->next = *lst;
        *lst = new;
    }
}


/*Itera una lista 'lst' y aplica la funcion 'f' en el contenido
de cada nodo*/

void	ft_lstiter(t_lst *lst, void (*f)(int))
{
	while (lst != NULL)
	{
		f(lst->value);
		lst = lst->next;
	}
}

/*Devuelve el ultimo nodo de la lista*/

t_lst	*ft_lstlast(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void    printlst(t_stack *stack)
{
	t_lst *current = stack->last;
    printf("----------------\n");
    printf("      PILA \n");
    printf("----------------\n");
    while (current != NULL)
    {
        printf("       %d\n", (int)current->value);
        current = current->next;
    }
	printf("\n");
}