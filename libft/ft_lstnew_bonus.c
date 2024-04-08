/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:13:41 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/08 14:13:43 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*Crea un nuevo nodo en la lista con malloc()

    La variable miembro 'content' se inicializa
    con el contenido del parametro 'content'. La
    variable 'next' con NULL
    
*/

t_list *ft_lstnew_bonus(void *content)
{
    t_list *new;
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

/*
int main(void)
{
    t_list *new = ft_lstnew_bonus("Primero");
    t_list *new2 = ft_lstnew_bonus("Segundo");
    t_list *new3 = ft_lstnew_bonus("Tercero");

    //Enlazar nodos
    new->next = new2;
    new2->next = new3;

    printlst(new);
}*/
