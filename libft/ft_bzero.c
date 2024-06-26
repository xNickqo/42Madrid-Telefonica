/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:08:10 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/14 21:20:21 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

/*Pone a 0 los primeros n bytes de un array */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = s;
	i = 0;
	while (i < n)
	{
		*temp++ = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	s[10];
	int	n = 5;
	ft_bzero(s, n);

	int i = 0;
	while (i < n)
	{
		printf("%d\n", s[i]);
		i++;
	}
	//[0, 0, 0 ,0 ,0, , , , ,]
}*/
