/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:37:34 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/09 19:37:36 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>
#include <stddef.h>

/*Itera una lista 'lst' y aplica la funcion 'f' en el contenido
de cada nodo*/

void    ft_lstiter_bonus(t_list *lst, void (*f)(void *))
{
    if (!lst || !f)
        return ; 
    while (lst != NULL)
    {
        f(lst->content);
        lst = lst->next;
    }
}

/*
int	main(void)
{
	// Creamos la lista
    t_list *lst = NULL;

    // Añadimos nodos a la lista
    lst = ft_lstnew_bonus("hello");
    ft_lstadd_front_bonus(&lst, ft_lstnew_bonus("first"));
    ft_lstadd_back_bonus(&lst, ft_lstnew_bonus("last"));

	ft_lstiter_bonus(lst, NULL);
	printlst(lst);
}*/