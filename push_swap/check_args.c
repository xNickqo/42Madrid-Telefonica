/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:45:14 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/22 20:02:09 by niclopez         ###   ########.fr       */
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
			ft_error("Error: Misplaced sign", NULL, NULL);
		if (ft_is_sign(argv[i]) && !ft_isdigit(argv[i + 1]))
			ft_error("Error: Sign without number or repeated", NULL, NULL);
		if (ft_isdigit(argv[i]) || argv[i] == ' ')
			consecutive_signs = 0;
		if (ft_is_sign(argv[i]) && consecutive_signs < 2)
			consecutive_signs++;
		if (!ft_isdigit(argv[i]) && !ft_is_sign(argv[i]) && argv[i] != ' ')
			ft_error("Error: Invalid character", NULL, NULL);
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;

	if (argc == 1)
		ft_error("Error: Missing arguments", NULL, NULL);
	i = argc - 1;
	while (i >= 1)
	{
		if (argv[i][0] == '\0')
			ft_error("Error: Empty argument", NULL, NULL);
		if (is_only_spaces(argv[i]))
			ft_error("Error: Argument with only spaces", NULL, NULL);
		tmp = ft_atoi(argv[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error: Number exceed limits", NULL, NULL);
		are_valid_args(argv[i]);
		i--;
	}
}
