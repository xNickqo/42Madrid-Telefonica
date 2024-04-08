#include "libft.h"
#include <stdio.h>

/*Añade el nodo 'new' al final de la lista 'lst'*/

void    ft_lstadd_back_bonus(t_list **lst, t_list *new)
{
    t_list  *last;

    if (new != NULL)
    {
        if (*lst == 0)
            *lst = new;
        else
        {
            last = ft_lstlast_bonus(*lst);
            last->next = new;
        }
    }
}
/*
int main(void)
{
    t_list  *lst = NULL;
    lst = ft_lstnew_bonus("principio");
    
    t_list  *last = ft_lstnew_bonus("final");
    ft_lstadd_back_bonus(&lst, last);

    printlst(lst);
}*/