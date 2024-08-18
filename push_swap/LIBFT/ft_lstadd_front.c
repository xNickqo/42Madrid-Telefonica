/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:13:48 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/08 14:14:01 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*Añade el nodo 'new' al principio de la lista 'lst'*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int main(void)
{
    t_list *lst = NULL;
    lst = ft_lstnew("Hello");

    t_list  *new = ft_lstnew("Primero");
    
    ft_lstadd_front(&lst, new);

    printlst(lst);
}*/