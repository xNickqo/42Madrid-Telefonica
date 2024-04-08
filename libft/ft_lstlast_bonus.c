#include "libft.h"
#include <stdio.h>

/*Devuelve el ultimo nodo de la lista*/

t_list*ft_lstlast_bonus(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    return (lst);
}