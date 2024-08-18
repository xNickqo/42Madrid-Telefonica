/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:18:29 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/09 15:18:32 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

/* Elimina y libera el nodo 'lst' dado y todos los consecutivos de ese nodo
utilizando la funcion 'del' y free().
Al final, el puntero a la lista debe ser NULL*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*borrar;

	if (*lst && del)
	{
		while (*(lst) != NULL)
		{
			borrar = *lst;
			*lst = borrar->next;
			del(borrar->content);
			free(borrar);
		}
		lst = NULL;
	}
}
/*
int main(void)
{
    // Creamos la lista
    t_list *lst = NULL;

    // Añadimos nodos a la lista
    lst = ft_lstnew("hola");
    ft_lstadd_front(&lst, ft_lstnew("first"));
    ft_lstadd_back(&lst, ft_lstnew("last"));

    // Imprimimos la lista antes de eliminar todos los nodos
    printf("Lista antes de eliminar todos los nodos:\n");
    printlst(lst);

    // Eliminamos y liberamos todos los nodos de la lista con la funcion 'del'
    ft_lstclear(&lst, NULL);

    // Imprimimos la lista después de eliminar todos los nodos
    printf("\nLista después de eliminar todos los nodos:\n");
    printlst(lst); // Debería imprimir una lista vacía
    
    return 0;
}*/
