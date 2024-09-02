/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:50:00 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/02 19:07:20 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#	include<unistd.h>
#	include<stdlib.h>
#	include<limits.h>
#	include<stdio.h>

typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *last;
} t_stack;

void	push(t_stack *stack, int value);
void    free_stack(t_stack *stack);
void    s(t_stack *stack);
void    p(t_stack *src, t_stack *dest);
void    r(t_stack *stack);
void	rr(t_stack *stack);

#endif