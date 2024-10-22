/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:49:33 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/22 20:34:27 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp && tmp->next)
	{
		if(tmp->value > tmp->next->value)
		{	
			ft_printf("KO\n");
			return ;
		}
		tmp = tmp->next;	
	}
	if (b != NULL)
	{	
		ft_printf("KO\n");
		return ;
	}
	else
	{	
		ft_printf("KO\n");
		return ;
	}
}

/*Crea una lista e introduce los valores dentro si no estan repetidos*/
void	init_values(t_list **lst, int value)
{
	t_list	*new_node;
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->value == value)
			ft_error("Error: Duplicate Element.", lst, NULL);
		tmp = tmp->next;
	}
	new_node = ft_lstnew(value);
	if (new_node)
		ft_lstadd_front(lst, new_node);
}

/* Procesa cada argumento y lo añade a la lista utilizando split()*/
int	process_args(char *argv, t_list **lst)
{
	char	**split;
	int		i;
	long	num;
	int		count;
	int		len;

	split = ft_split(argv, ' ');
	if (!split)
		ft_error("Error: Could not split the string.", lst, NULL);
	len = 0;
	while (split[len])
		len++;
	i = len - 1;
	count = 0;
	while (i >= 0)
	{
		num = ft_atoi(split[i]);
		init_values(lst, num);
		free(split[i]);
		i--;
		count++;
	}
	free(split);
	return (count);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		numbers;

	a = NULL;
	b = NULL;
	check_args(argc, argv);
	numbers = 0;
	i = argc - 1;
	while (i >= 1)
	{
		numbers += process_args(argv[i], &a);
		i--;
	}
	if (!is_sorted(a))
	{
		if (numbers <= 5)
			simple_sort(&a, &b);
		else
			radix_sort(&a, &b);
	}
	checker(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
