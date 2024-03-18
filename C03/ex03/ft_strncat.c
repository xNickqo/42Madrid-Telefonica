/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:56:02 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/20 16:11:06 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*temp;

	temp = dest;
	i = 0;
	while (*dest != '\0')
	{
		dest++;
	}
	while (i < nb && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (temp);
}
/*
int	main(void)
{
	char	a[] = "Hello";
	char	b[] = "World";
	ft_strncat(a, b, 2);
	printf("El destino es igual a : %s \n", a);
	printf("%s\n", b);
	
	char	c[] = "Hello";
	char	d[] = "World";
	strncat(c, d, 2);
	printf("El destino es igual a : %s \n", c);
	printf("%s\n", d);
}*/
