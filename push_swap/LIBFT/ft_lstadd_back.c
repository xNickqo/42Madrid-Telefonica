/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:00:06 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/10 18:04:56 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
/*
int main(void)
{
    t_list  *lst = NULL;
    lst = ft_lstnew("principio");
    
    t_list  *last = ft_lstnew("final");
    ft_lstadd_back(&lst, last);

    printlst(lst);
}*/
