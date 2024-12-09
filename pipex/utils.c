/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:20:34 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/09 21:38:11 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
	Función: get_env_path
	Descripción:
		Busca la variable 'PATH' en el entorno recibido como argumento.
		- Recorre el arreglo 'env' para encontrar la variable 
			que comienza con "PATH=".
	Parámetros:
		- 'env': Arreglo de cadenas que representan el entorno del sistema.
	Retorna:
		- Un puntero al valor de la variable 'PATH' en el entorno. 
			(EXCLUYENDO 'PATH=').
*/
char	*get_env_path(char **env)
{
	int	i;
	int	exist;

	exist = 0;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			exist = 1;
			break ;
		}
		i++;
	}
	if (exist == 0)
		ft_error("PATH not found in the env", EXIT_FAILURE);
	return (env[i] + 5);
}

/* 
	Función: find_cmd
	Descripción:
		Busca la ruta completa de un comando ejecutable.
		- Obtiene el valor de la variable 'PATH' con 'get_env_path()'.
		- Divide el 'PATH' en rutas individuales usando 'ft_split()'.
		- Recorre cada ruta, concatenándola con el nombre del 
			comando 'cmd' para generar una posible ruta completa.
		- Verifica si el archivo en esa ruta es ejecutable utilizando `access`.
	Parámetros:
		- 'cmd': El comando que se desea encontrar.
		- 'env': Arreglo de cadenas que representan el entorno del sistema.
	Retorna:
		- Un puntero a la ruta completa del comando, o NULL si no se encuentra.
*/
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
	while (paths[i])
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

/* Muestra un mensaje de error en la salida estándar de errores (sterr) 
	utilizando `perror` y finaliza la ejecución del programa 
	con un código de salida especificado.*/
void	ft_error(char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

/* Libera la memoria asignada a un arreglo de cadenas. */
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

/* 
	Función: open_file
	Descripción:
		Abre un archivo en el modo especificado.
		- Si el modo es 0, se abre el archivo en modo LECTURA.
		- Si el modo es 1, se abre el archivo en modo ESCRITURA, 
		  	creando el archivo si no existe o truncándolo si ya existe.
	Parámetros:
		- 'file': El nombre del archivo a abrir.
		- 'mode': El modo en que se abrirá el archivo.
	Retorna:
		- El descriptor de archivo abierto.
*/
int	open_file(char *file, int mode)
{
	int	fd;

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
