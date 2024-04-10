/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:05:10 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/09 14:06:55 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

/* Toma como parametro un nodo de 'lst' y libera la memoria del contenido
 * utilizando la funcion 'del' dada como parametro, ademas de liberar el 
 * nodo. La memoria de 'next' no debe liberarse.*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
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

    // Imprimimos la lista antes de eliminar el último nodo
    printf("Lista antes de eliminar el último nodo:\n");
    printlst(lst);

    // Imprimimos el contenido del último nodo que se eliminará
    printf("\nContenido del último nodo 
			que se eliminará: %s\n", (char *)ft_lstlast(lst)->content);

    // Eliminamos el último nodo de la lista seguido de la funcion 'del'
    ft_lstdelone(ft_lstlast(lst), NULL);

    // Imprimimos la lista después de eliminar el último nodo
    printf("\nLista después de eliminar el último nodo:\n");
    printlst(lst);

    return 0;
}*/