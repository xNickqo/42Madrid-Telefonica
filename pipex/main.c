/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:22:46 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/27 22:09:10 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
Ejecuta un comando, localizando su ruta mediante `find_cmd` y ejecutándolo 
con `execve`.

Paso a paso:
 * 1. Divide el comando `command` usando ' ' como delimitador con `ft_split`.
 * 2. Llama a `find_cmd` para obtener la ruta completa del comando.
 * 3. Si `find_cmd` retorna NULL, significa que el comando no se encontró, 
 * 		por lo que muestra un error.
 * 4. Si la ruta del comando es encontrada, usa `execve` para ejecutar el 
 * 		comando con sus argumentos.
 * 5. Si `execve` falla, libera los recursos y termina el programa con 
 * 		un mensaje de error.
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
Función para el proceso hijo. Redirige la entrada estándar desde un archivo
y la salida estándar a través de un pipe. Luego ejecuta el comando `cmd1`.

Paso a paso:
 * 1. Abre el archivo `infile` en modo lectura.
 * 2. Redirige la entrada estándar al archivo abierto con `dup2`.
 * 3. Redirige la salida estándar al lado de escritura del pipe con `dup2`.
 * 4. Cierra los descriptores de archivo.
 * 5. Llama a `exec` para ejecutar el comando `cmd1`.
 */
void	child(char **argv, int *pipe_fd, char **env)
{
	int		fd;
	char	*infile;
	char	*cmd1;

	infile = argv[1];
	fd = open_file(infile, 0);
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_error("Error in dup2 child read", EXIT_FAILURE);
	close(fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		ft_error("Error in dup2 child write", EXIT_FAILURE);
	close(pipe_fd[0]);
	cmd1 = argv[2];
	exec(cmd1, env);
}

/* 
Función para el segundo proceso. Redirige la entrada estándar desde un pipe
y la salida estándar hacia un archivo. Luego ejecuta el comando `cmd2`.

Paso a paso:
 * 1. Redirige la entrada estándar al lado de lectura del pipe con `dup2`.
 * 2. Abre el archivo `outfile` en modo escritura.
 * 3. Redirige la salida estándar al archivo abierto.
 * 4. Cierra los descriptores de archivo y el lado de escritura del pipe.
 * 5. Llama a `exec` para ejecutar el comando `cmd2`.
 */
void	child2(char **argv, int *pipe_fd, char **env)
{
	int		fd;
	char	*outfile;
	char	*cmd2;

	outfile = argv[4];
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		ft_error("Error in dup2 child2 read", EXIT_FAILURE);
	close(pipe_fd[1]);
	fd = open_file(outfile, 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		ft_error("Error in dup2 child2 write", EXIT_FAILURE);
	close(fd);
	cmd2 = argv[3];
	exec(cmd2, env);
}

/* Espera a que los dos procesos hijos terminen su ejecución. */
void	waitchilds(pid_t *pid)
{
	int	status;
	int	i;

	i = 0;
	while (i < 2)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
}

/* 
Función principal que inicializa el pipe, crea los procesos hijos y ejecuta
las funciones correspondientes para el manejo de archivos, redirección de pipes
y ejecución de los comandos `cmd1` y `cmd2`.

Paso a paso:
 * 1. Verifica que el número de argumentos sea correcto.
 * 2. Crea un pipe para la comunicación entre los procesos hijos.
 * 3. Crea los procesos con `fork`.
 * 5. El proceso padre cierra los descriptores del pipe y espera 
 * 		que ambos procesos hijos terminen.
 */
int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	pid[2];

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_fd) == -1)
		ft_error("Error creating the pipe", EXIT_FAILURE);
	pid[0] = fork();
	if (pid[0] == -1)
		ft_error("Error in pid[0]", EXIT_FAILURE);
	if (pid[0] == 0)
		child(argv, pipe_fd, env);
	pid[1] = fork();
	if (pid[1] == -1)
		ft_error("Error in pid[1]", EXIT_FAILURE);
	if (pid[1] == 0)
		child2(argv, pipe_fd, env);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitchilds(pid);
}
