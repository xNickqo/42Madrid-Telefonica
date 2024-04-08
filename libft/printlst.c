#include <stdio.h>
#include "libft.h"

void    printlst(t_list *lst)
{
    int i = 1;
    printf("----------------\n");
    printf(" Lista Enlazada \n");
    printf("----------------\n");
    while (lst != NULL)
    {
        printf("%d. %s\n", i, (char *)lst->content);
        lst = lst->next;
        i++;
    }
}