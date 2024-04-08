#include "libft.h"
#include <stdio.h>

/*Cuenta el numero de nodos de una lista*/

int ft_lstsize_bonus(t_list *lst)
{
    int count;

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
    lst = ft_lstnew_bonus("Hello");
    t_list *lst2 = ft_lstnew_bonus("World");
    t_list *lst3 = ft_lstnew_bonus("!");

    //Enlazar nodos
    lst->next = lst2;
    lst2->next = lst3;

    printlst(lst);

    printf("El numero de nodos de esta lista es: %d\n",ft_lstsize_bonus(lst));
}*/