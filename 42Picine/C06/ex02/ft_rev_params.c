/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:38:52 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/27 12:06:24 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	strlenargv(char argv[])
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*Igualo i al numero de argumentos - 1
 * argc = 3
 * *argv[2]
 *
 * Mientras i sea menor que el numero de argumentos
 * imprime el argumento 
 * i--*/

int	main(int argc, char *argv[])
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		write(1, argv[i], strlenargv(argv[i]));
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
