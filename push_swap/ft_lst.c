/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:13:16 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/02 23:42:02 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Crea un nuevo nodo en la lista con malloc() 
	la variable miembro 'value' se inicializa 
	con el contenido del parametro 'value'. La
	variable 'next' con NULL*/
t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

/*Añade el nodo 'new' al principio de la lista 'lst'*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*Devuelve el ultimo nodo de la lista*/
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*Añade el nodo 'new' al final de la lista 'lst'*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new != NULL)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
	}
}

/* Cuenta el numero de nodos de una lista */
int	ft_lstsize(t_list *lst)
{
	int	i;
	
	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/* Imprime la lista */
void printList(t_list *a, t_list *b)
{
    t_list *tmp_a = a;
    t_list *tmp_b = b;

    printf("\n----------------\n");
    printf("A: ");
    if (tmp_a == NULL)
        printf("Empty\n");
    else
    {
        while (tmp_a)
        {
            printf("%d", tmp_a->value);
            if (tmp_a->next)
                printf(" -> ");
            tmp_a = tmp_a->next;
        }
        printf(" -> NULL\n");
    }

    printf("b: ");
    if (tmp_b == NULL)
        printf("Empty\n");
    else
    {
        while (tmp_b)
        {
            printf("%d", tmp_b->value);
            if (tmp_b->next)
                printf(" -> ");
            tmp_b = tmp_b->next;
        }
        printf(" -> NULL\n");
    }
    printf("----------------\n");
}