/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:36:12 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/27 12:07:05 by niclopez         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		write(1, argv[i], strlenargv(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
