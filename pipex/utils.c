/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:20:34 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/27 19:57:39 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
Busca y devuelve el valor de la variable de entorno "PATH".
Si no se encuentra "PATH", termina el programa con un mensaje de error.
  
Paso a paso:
 * 1. Itera sobre cada elemento del array `env`.
 * 2. Busca el valor "PATH=" en cada elemento de `env` mediante `ft_strncmp`.
 * 3. Si lo encuentra, devuelve la parte de la cadena después de "PATH=".
 * 4. Si no lo encuentra en ningún elemento, termina el programa.
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
Busca el comando especificado en el entorno utilizando el PATH.
Devuelve la ruta completa del comando si es encontrada, sino devuelve NULL.

Paso a paso:
 * 1. Obtiene la variable de entorno "PATH" llamando a `get_env_path`.
 * 2. Divide la cadena "PATH" en diferentes directorios usando `ft_split`.
 * 3. Itera sobre cada directorio en el array `paths`.
 * 4. Para cada directorio, concatena el directorio con el comando 
 * 		utilizando `ft_strjoin`.
 * 5. Verifica si el archivo existe y tiene permisos de ejecución 
 * 		usando `access(cmd_path, X_OK)`.
 * 6. Si lo encuentra, libera el array de directorios `paths` y retorna 
 * 		la ruta del comando.
 * 7. Si no encuentra el comando en ninguno de los directorios, 
 * 		libera el array de directorios y devuelve `NULL`.
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

/* Muestra un mensaje de error y termina el programa con el código de 
salida proporcionado. */
void	ft_error(char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

/* Libera la memoria ocupada por un arreglo de cadenas (split) de strings. */
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

/* Abre un archivo en modo lectura (0) o escritura (1) y retorna el 
descriptor de archivo.*/
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
