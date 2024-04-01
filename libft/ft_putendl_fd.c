/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:37:37 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/01 21:44:36 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>

/* Envia la cadena de caracteres 's' al descriptor de archivo especificado 
 * seguido de un salto de linea
 *
 * Osea, es igual que ft_putstr_fd pero con un salto de linea al
 * finalizar la cadena*/

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	 write(fd, "\n", 1);
}
/*
int	main(void)
{
	char	*s = "Hola mundo";
	ft_putendl_fd(s, 1);
}*/
