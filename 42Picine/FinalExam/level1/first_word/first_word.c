/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:29:24 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/29 23:32:58 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	first_word(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] && !is_space(str[i]))
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		first_word(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
