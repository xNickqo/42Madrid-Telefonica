/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:50:00 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/02 23:30:57 by niclopez         ###   ########.fr       */
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

typedef struct s_lst
{
	int				value;
	struct s_lst	*next;
}					t_lst;

typedef struct s_stack
{
	t_lst *last;
} 			t_stack;

t_lst		*ft_lstnew(int value);
void		ft_lstadd_front(t_lst **lst, t_lst *new);
t_lst		*ft_lstlast(t_lst *lst);
void		ft_lstiter(t_lst *lst, void (*f)(int));
void    	printlst(t_stack *stack);

void	push(t_stack *stack, int value);
void    free_stack(t_stack *stack);
void    s(t_stack *stack);
void    p(t_stack *src, t_stack *dest);
void    r(t_stack *stack);
void	rr(t_stack *stack);

#endif