/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:19:33 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/10 18:36:48 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*Cuenta el numero de nodos de una lista*/

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
int main(void)
{
    t_list *lst = NULL;
    lst = ft_lstnew("Hello");
    t_list *lst2 = ft_lstnew("World");
    t_list *lst3 = ft_lstnew("!");

    //Enlazar nodos
    lst->next = lst2;
    lst2->next = lst3;

    printlst(lst);

    printf("El numero de nodos de esta lista es: %d\n",ft_lstsize(lst));
}*/
