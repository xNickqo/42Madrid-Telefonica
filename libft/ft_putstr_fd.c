/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:25:57 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/01 21:34:23 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

/* La funcion envia cadenas de caracteres 's' al descriptor de archivo
 * especificado por 'fd'.
 *
 * Basicamente escribe la cadena en el archivo correspondiente.*/

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
/*
int     main(void)
{
	//Escribe la cadena 's' en la salida estandar (descriptor de archivo 1)
	char	*s = "Hola mundo\n";
        ft_putstr_fd(s, 1);

	//Escribir la cadena 's' en una archivo (descriptor de archivo 2)
	int    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	ft_putstr_fd(s, fd);
	close(fd);
}*/
