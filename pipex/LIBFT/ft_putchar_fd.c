/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:16:45 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/01 21:37:04 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

/* Envia el caracter 'c' al file descriptor especificado */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	//Escribe el caracter 'a' en la salida estandar (descriptor de archivo 1) 
	ft_putchar_fd('a', 1);

	//Escribir el caracter 'b' en una archivo (descriptor de archivo 2)
	int	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	ft_putchar_fd('b', fd);
	close(fd);
}*/
