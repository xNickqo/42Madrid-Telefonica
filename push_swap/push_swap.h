/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:50:00 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/11 17:50:33 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#	include<unistd.h>
#	include<stdlib.h>
#	include<limits.h>
#	include<stdio.h>
#	include"libft.h"
#	include"ft_printf.h"

// Stack
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

// Util functions
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	printList(t_list *lst);
int		ft_lstsize(t_list *lst);

// Instruction functions
int		swap(t_list **lst);
int		push(t_list **lst_src, t_list **lst_dest);
int		rotate(t_list **lst);
int		reverseRotate(t_list **lst);

int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);
int		pa(t_list **a, t_list **b);
int		pb(t_list **b, t_list **a);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);

void init_values(t_list **lst, int value);
void	free_stack(t_list **lst);

#endif