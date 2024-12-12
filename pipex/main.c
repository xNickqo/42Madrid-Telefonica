/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:22:46 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/12 21:28:08 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
	Función: exec
	Descripción:
		Esta función recibe un comando y lo ejecuta en un proceso hijo.
		- Busca la ruta del comando en 'env' mediante la función `find_cmd`.
		- Si la ruta del comando se encuentra, se ejecuta usando `execve`.
	Parámetros:
		- 'command': El comando a ejecutar.
		- 'env': El entorno del sistema operativo (variables de entorno).
*/
void	exec(char *command, char **env)
{
	char	**split;
	char	*path;

	split = ft_split(command, ' ');
	path = find_cmd(split[0], env);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(split[0], 2);
		ft_free(split);
		exit(EXIT_FAILURE);
	}
	if (execve(path, split, env) == -1)
	{
		free(path);
		ft_free(split);
		ft_error("Error executing command", EXIT_FAILURE);
	}
}

/* 
	Función: child
	Descripción:
		PROCESO HIJO (copia del proceso padre).
		- Redirige la salida estándar del 'cmd1' a un archivo 
			de entrada 'infile'.
		- Cierra el descriptor de lectura de la pipe, ya que el hijo no 
			necesita leer de la pipe.
		- Luego ejecuta el primer comando 'cmd1' con la función 'exec'.
	Parámetros:
		- 'argv': Argumentos pasados al programa.
		- 'p_fd': Los descriptores de la pipe.
		- 'env': El entorno del sistema operativo.
*/
void	child(char **argv, int *p_fd, char **env)
{
	int		fd;
	char	*infile;

	infile = argv[1];
	fd = open_file(infile, 0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	fd = open_file(infile, 1);
	dup2(p_fd[1], STDOUT_FILENO);
	close(fd);
	close(p_fd[0]);
	exec(argv[2], env);
}

/* 
	Función: parent
	Descripción:
		PROCESO PADRE.
		- Redirige la entrada estándar del 'cmd2' desde un 
			archivo de entrada 'infile'.
		- Redirige la salida estándar del 'cmd2' a un 
			archivo de salida 'outfile'.
		- Cierra el descriptor de escritura de la pipe, ya que el padre 
			no necesita escribir en la pipe.
		- Luego ejecuta el segundo comando 'cmd2' con la función `exec`.
	Parámetros:
		- 'argv': Argumentos pasados al programa.
		- 'p_fd': Los descriptores de la pipe utilizados para la comunicación 
					entre padre e hijo.
		- 'env': El entorno del sistema operativo.
*/
void	parent(char **argv, int *p_fd, char **env)
{
	int		fd;
	char	*outfile;
	char	*infile;

	infile = argv[1];
	outfile = argv[4];
	fd = open_file(infile, 0);
	dup2(p_fd[0], STDIN_FILENO);
	close(fd);
	fd = open_file(outfile, 1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(p_fd[1]);
	exec(argv[3], env);
}

/* 
	Función: main
	Descripción:
		- Verifica el número de argumentos pasados al programa.
		- Crea una pipe que permite la comunicación entre padre e hijo.
		- Llama a fork() para crear un proceso hijo.
		- En el proceso hijo, ejecuta la función 'child' para redirigir su 
			salida a un archivo y ejecutar el primer comando.
		- En el proceso padre, espera que el proceso hijo termine y luego 
			ejecuta la función 'parent' para redirigir su entrada desde 
			un archivo y ejecutar el segundo comando.
	Parámetros:
		- 'argc': El número de argumentos pasados al programa.
		- 'argv': Los argumentos pasados al programa.
		- 'env': El entorno del sistema operativo (variables de entorno).
*/
int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid[2];
	int		status;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(p_fd) == -1)
		ft_error("Error creating the pipe", EXIT_FAILURE);
	pid[0] = fork();
	if (pid[0] == -1)
		ft_error("Error in pid[0]", EXIT_FAILURE);
	if (pid[0] == 0)
		child(argv, p_fd, env);
	
	
	pid[1] = fork();
	if (pid[1] == -1)
		ft_error("Error in pid[1]", EXIT_FAILURE);
	if (pid[1] == 0)
		parent(argv, p_fd, env);
	
	close(p_fd[0]);
	close(p_fd[1]);

	int i = 0;
	while(i < 2)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
}
