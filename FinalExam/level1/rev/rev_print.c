/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:22:44 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/01 00:39:26 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int lenargv(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	int i;
	int len;

	i= 0;
	if(argc == 2)
	{
		len = lenargv(argv[1]);
		while(i < len)
		{
			len--;
			write(1, &argv[1][len], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
