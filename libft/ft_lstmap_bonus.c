/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:56:16 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/09 19:56:18 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include "libft.h"
#include <stdio.h>

/*Itera la lista 'lst' y aplica la funcion 'f' al contenido de cada nodo.
Crea una lista resultante de la aplicacion correcta y sucesiva de la funcion
'f' sobre cada nodo. LA funcion 'del' se utiliza para eliminar el contenido
de un nodo, si hace falta.*/

t_list  *ft_lstmap_bonus(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    if (!lst || !f || !del)
        return ;
    while (lst != NULL)
    {
        f(lst->content);
        del(lst->content);
        lst = lst->next;
    }
    return (lst);
}