/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:50:00 by niclopez          #+#    #+#             */
/*   Updated: 2024/08/18 20:58:58 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#	include<unistd.h>
#	include<stdlib.h>
#	include<limits.h>
#	include<stdio.h>

typedef struct s_list
{
	int	*sa;
	int	*sb;
	int	*ss;
	int	*pa;
	int	*pb;
	int	*ra;
	int	*rb;
	int	*rr;
	int	*rra;
	int	*rrb;
	int	*rrr;

	int *argc;

}	t_list;

typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;


int	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif