typedef struct s_list{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_foraech(t_list *begin_list, void (*f)(void *)){
    t_list *current = begin_list;
    while(current){
        (*f)(current->data);
        current = current->next;
    }
}