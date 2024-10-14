/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:50:00 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/14 19:39:05 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#	include <unistd.h>
#	include <stdlib.h>
#	include <limits.h>
#	include <stdio.h>
#	include "libft.h"
#	include "ft_printf.h"

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
int		ft_lstsize(t_list *lst);
void	printlst(t_list *a, t_list *b);

// Instruction functions
int		swap(t_list **lst);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);

int		push(t_list **lst_src, t_list **lst_dest);
int		pa(t_list **a, t_list **b);
int		pb(t_list **b, t_list **a);

int		rotate(t_list **lst);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);

int		reverse_rotate(t_list **lst);
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);

// Check args
void	check_args(int argc, char **argv);
int		ft_is_sign(char c);
int		is_only_spaces(char *argv);
void	are_valid_args(char *argv);

// MAIN
void	init_values(t_list **lst, int value);
void	free_stack(t_list **lst);
void	ft_error(char *message, t_list **a, t_list **b);
int		is_sorted(t_list *a);

// Simple sort
int		get_min_pos(t_list *a);
void	move_to_top(t_list **a, int pos);
void	small_sort(t_list **a);
void	simple_sort(t_list **a, t_list **b);

void quick_sort(t_list **a, t_list **b);
void sort_b(t_list **b);
void sort_a(t_list **a);
int get_pivot(t_list **a);
int is_closer_to_end(t_list **lst, t_list *target);
void move_to_top_a(t_list **a, t_list *target);
void move_to_top_b(t_list **b, t_list *target);

#endif