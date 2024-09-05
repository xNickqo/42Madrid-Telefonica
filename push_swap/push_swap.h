/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:50:00 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/05 20:04:50 by niclopez         ###   ########.fr       */
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
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	printList(t_list *head);
int		ft_lstsize(t_list *head);

// Instruction functions
int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverseRotate(t_list **stack);

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

void	init_values(t_list *stack, int value);
void	free_stack(t_list **stack);

#endif