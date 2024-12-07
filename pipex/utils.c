/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:20:34 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/07 21:06:46 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg, int exit_code)
{
    perror(msg);
    exit(exit_code);
}

void	ft_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int open_file(char *file, int mode)
{
    int fd;

    if (mode == 0)
    {
        fd = open(file, O_RDONLY, 0777);
        if (fd == -1)
            ft_error("Error opening input file", EXIT_FAILURE);
    }
    if (mode == 1)
    {
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (fd == -1)
            ft_error("Error opening output file", EXIT_FAILURE);
    }
    return (fd);
}
