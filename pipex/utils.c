/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:20:34 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/02 18:45:10 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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


int	open_file(char* file, int n)
{
	int ret;

	if(n == 0)
		ret = open(file, O_RDONLY);
	if(n == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(ret == -1)
	{
		perror("Error, can't open the file");
		return 1;
	}
	return (ret);
}