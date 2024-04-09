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

void    ft_lstclear_bonus(t_list **lst, void (*del)(void *))
{
    t_list  *temp;
    t_list  *next;

    *lst = temp;
    while (temp != NULL)
    {
        //Guardamos la direccion del siguiente nodo
        next = temp->next;
        //Eliminamos el contenido del nodo actual
        del(temp->content);
        //Liberamos la memoria ocupada por ese nodo
        free(temp);
        //Avanzamos al siguiente nodo
        temp = next;
    }
    *lst = NULL;
}
/*
int main(void)
{
    // Creamos la lista
    t_list *lst = NULL;

    // Añadimos nodos a la lista
    lst = ft_lstnew_bonus("hola");
    ft_lstadd_front_bonus(&lst, ft_lstnew_bonus("first"));
    ft_lstadd_back_bonus(&lst, ft_lstnew_bonus("last"));

    // Imprimimos la lista antes de eliminar todos los nodos
    printf("Lista antes de eliminar todos los nodos:\n");
    printlst(lst);

    // Eliminamos y liberamos todos los nodos de la lista con la funcion 'del'
    ft_lstclear_bonus(&lst, NULL);

    // Imprimimos la lista después de eliminar todos los nodos
    printf("\nLista después de eliminar todos los nodos:\n");
    printlst(lst); // Debería imprimir una lista vacía
    
    return 0;
}*/

