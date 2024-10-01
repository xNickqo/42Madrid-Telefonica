/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:45:14 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/01 23:41:42 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_spaces(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

void	are_valid_args(char *argv)
{
	int	i;
	int	consecutive_signs;

	i = 0;
	consecutive_signs = 1;
	while (argv[i])
	{
		if (ft_is_sign(argv[i]) && argv[i - 1] != ' ' && i != 0)
			ft_error("Error: signo mal colocado", NULL, NULL);
		if (ft_is_sign(argv[i]) && !ft_isdigit(argv[i + 1]))
			ft_error("Error: signo sin numero", NULL, NULL);
		if (ft_isdigit(argv[i]) || argv[i] == ' ')
			consecutive_signs = 0;
		if (ft_is_sign(argv[i]) && consecutive_signs < 2)
			consecutive_signs++;
		if (!ft_isdigit(argv[i]) && !ft_is_sign(argv[i]) && argv[i] != ' ')
			ft_error("Error: caracter no valido", NULL, NULL);	
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		ft_error("Error: debe haber argumentos", NULL, NULL);
	i = 1;
	while(i < argc)
	{
		if (argv[i][0] == '\0')
			ft_error("Error el argumento no puede estra vacio", NULL, NULL);
		if (is_only_spaces(argv[i]))
			ft_error("Error el argumento no debe contener solo espacios", NULL, NULL);
		are_valid_args(argv[i]);
		i++;
	}
}
