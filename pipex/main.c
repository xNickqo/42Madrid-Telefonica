/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:22:46 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/07 21:11:42 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Buscar el PATH en el entorno
char	*get_env_path(char **env)
{
	int	i;
	int	exist;

	exist = 0;
	i = 0;
    while(env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			exist = 1;
            break ;
		}
    	i++;
    }
	if (exist == 0)
		ft_error("PATH not found in the env", 1);
	return (env[i] + 5);
}

//Encontrar la ruta completa de un comando
char	*find_cmd(char *cmd, char **env)
{
	char	*path_env;
	char	**paths;
	char	*cmd_path;
	char	*tmp;
	int		i;

	path_env = get_env_path(env);
	paths = ft_split(path_env, ':');
	i = 0;
	while(paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
		{
			ft_free(paths);
            return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free(paths);
    return (NULL);
}

// Ejecutar un comando con manejo de errores
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
        perror("Error executing command");
        free(path);
        ft_free(split);
        exit(EXIT_FAILURE);
    }
}

void child(char **argv, int *p_fd, char **env)
{
    int 	fd;
	char	*infile;

	infile = argv[1];

    // Aquí se debe redirigir la salida de cmd1 a infile
    fd = open_file(infile, 1);  // Abrir infile (como archivo de salida)
    dup2(fd, STDOUT_FILENO);  // Redirigir salida de cmd1 a infile
    close(fd);

    close(p_fd[0]); // Cerrar el descriptor de lectura de la pipe
    exec(argv[2], env); // Ejecutar cmd1
}

void parent(char **argv, int *p_fd, char **env)
{
    int 	fd;
	char	*outfile;
	char	*infile;

	infile = argv[1];
	outfile = argv[4];

    // Aquí se debe leer infile como entrada y redirigir salida a outfile
    fd = open_file(infile, 0);  // Abrir infile (como archivo de entrada)
    dup2(fd, STDIN_FILENO);  // Redirigir entrada de cmd2 desde infile
    close(fd);

    fd = open_file(outfile, 1);  // Abrir outfile (como archivo de salida)
    dup2(fd, STDOUT_FILENO);  // Redirigir salida de cmd2 a outfile
    close(fd);

    close(p_fd[1]);  // Cerrar el descriptor de escritura de la pipe
    exec(argv[3], env);  // Ejecutar cmd2
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;
	int		status;

	if (argc != 5)
		ft_error("Usage: ./pipex infile cmd1 cmd2 outfile", -1);
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(argv, p_fd, env);
	else
	{
		waitpid(pid, &status, 0);
		parent(argv, p_fd, env);
	}
	close(p_fd[0]);
	close(p_fd[1]);
}
