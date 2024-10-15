/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:49:33 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/15 20:08:08 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Crea una lista e introduce los valores dentro si no estan repetidos*/
void init_values(t_list **lst, int value)
{
    t_list  *new_node;
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->value == value)
			ft_error("Error: elemento duplicado.", lst, NULL);
		tmp = tmp->next;
	}
    new_node = ft_lstnew(value);
    if (new_node)
        ft_lstadd_front(lst, new_node);
}

/*Libera la memoria de reservada de una pila*/
void	free_stacks(t_list **a, t_list **b)
{
	t_list	*tmp;
	
	if (a == NULL && b == NULL)
		return ;
	if (a != NULL)
	{
        while (*a)
		{
            tmp = *a;
            *a = (*a)->next;
            free(tmp);
        }
        *a = NULL;
    }
	if (b != NULL)
	{
        while (*b)
		{
            tmp = *b;
            *b = (*b)->next;
            free(tmp);
        }
        *b = NULL;
    }
}

void	ft_error(char *message, t_list **a, t_list **b)
{
	ft_putendl_fd(message, 2);
	free_stacks(a, b);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	process_args(char *argv, t_list **lst)
{
	char	**split;
	int		i;
	int		num;

	split = ft_split(argv, ' ');
	if (!split)
		ft_error("Error: fallo al dividir la cadena.", lst, NULL);
	i = 0;
	while (split[i])
	{
		num = ft_atoi(split[i]);
		init_values(lst, num);
		free(split[i]);
		i++;
	}
	free(split);
}

int main(int argc, char *argv[])
{
    t_list *a;
    t_list *b;
	int i;

    a = NULL;
    b = NULL;
	check_args(argc, argv);
	i = 1;
	while (i < argc)
	{
		process_args(argv[i], &a);
		i++;
	}
    if (!is_sorted(a))
    {
		if (argc <= 6)
			simple_sort(&a, &b);
		else
			quick_sort(&a, &b);
	}
	ft_printf("\n\nLista ordenada:");
    printlst(a, b);
    free_stacks(&a, &b);
    return (0);
}
