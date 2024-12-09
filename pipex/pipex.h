/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:29:01 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/09 21:38:15 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	
	open, close, read, write,
	malloc, free, perror,
	strerror, access, dup, dup2,
	execve, exit, fork, pipe,
	unlink, wait, waitpid 
*/
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

char	*get_env_path(char **env);
char	*find_cmd(char *cmd, char **env);
void	ft_error(char *msg, int exit_code);
void	ft_free(char **split);
int		open_file(char *file, int n);

#endif