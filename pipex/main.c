/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:22:46 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/02 19:24:09 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/*Uso de dup2 para redirigir los descriptores de archivo: 
En las funciones child y parent, estás llamando a dup2 para redirigir los 
descriptores estándar de entrada (0, es decir, stdin) 
y salida (1, es decir, stdout) a archivos o extremos del pipe. 
Esto significa que, una vez que haces estas redirecciones, todo lo que 
intentes imprimir con ft_printf se escribe en el archivo o el pipe, en lugar 
de mostrarse en la terminal.*/
void	exec(char *command, char **env)
{
	char	**split;

	split = ft_split(command, ' ');

	int i = 0;
	while (split[i])
	{
		ft_printf("Command[%d]: %s\n", i, split[i]);
		i++;
	}

	i = 0;
	while (env[i])
	{
		ft_printf("Env[%d]: %s\n", i, env[i]);
		i++;
	}

	//Funcion que encuentre la ubicacion del comando a usar
	char *path = "/bin/ls";
	if ((execve(path, split, env) == -1))
	{
		ft_putstr_fd("Command not found:  ", 2);
		ft_putendl_fd(split[0], 2);
		ft_free(split);
	}
	
}

void	child(char **argv, int *parent_fd, char **env)
{
	int	fd;

	// Abrimos el archivo de lectura 
	fd = open_file(argv[1], 0);

	// Redirige la entrada estandar (STDIN) al archivo (argv[1])
	dup2(fd, 0);

	// Redirige la salida estandar (STDOUT) al descriptor de escritura de la pipe
	dup2(parent_fd[1], 1);

	close(parent_fd[0]);

	// Ejecuta el comando especificado
	exec(argv[2], env);
}

void	parent(char **argv, int *parent_fd, char **env)
{
	int		fd;

	// Abrimos el archvo de escritura
	fd = open_file(argv[4], 1);

	// Redirige  la salida estandar (STDOUT) al archivo (argv[4])
	dup2(fd, 1);

	// Redirige la entrada estandar (STDIN) a la lectura de la pipe , haciendo que el comando se lea desde la pipe
	dup2(parent_fd[0], 0);
	
	close(parent_fd[1]);

	// Ejecuta el comando especificado
	exec(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int	parent_fd[2];
	pid_t	pid;

	if(argc != 5)
		return 1;
	
	if(pipe(parent_fd) == -1)
		return 1;
	
	pid = fork();
	if(pid == -1)
		return 1;
	
	if (pid == 0)
		child(argv, parent_fd, env);
	parent(argv, parent_fd, env);
	
	return 0;
}
