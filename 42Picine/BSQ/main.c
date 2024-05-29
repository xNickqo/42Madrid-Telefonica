/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:57:30 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/27 16:35:58 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096 //Tamaño reservado en la memoria

/*int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/

void	reemplazar_caracteres(char	*mapa)
{
	int	i;

	i = 0;
	while (mapa[i] != '\0')
	{
		if (mapa[i] == '.')
			mapa[i] = 'x';
		i++;
	}
}

char	*leer_mapa(char	*nombre_archivo)
{
	/*Usaremos malloc() para asignar un espacio en memoria para el
	 * contenido del archivo
	 *
	 * Es necessario porque no se conoce la cantidad exacta de memoria
	 * requerida y puede variar dependiendo del tamaño del archivo*/
	int		archivo;
	char	*buffer = (char *)malloc(BUFFER_SIZE);
	
	//Memoria insuficiente ? 
	if (buffer == NULL)
	{
		write(1, "Error\n", 28);
		exit(1);
	}

	//Abrir el archivo en modo lectura
	archivo = open(nombre_archivo, O_RDONLY);

	//Leemos el contenido del archivo abierto anteriormente
	ssize_t	bytes_leidos;
	bytes_leidos = read(archivo, buffer, BUFFER_SIZE);

	//Cerramos el archivo
	close(archivo);

	return (buffer);
}

int main(int argc, char *argv[])
{
	int	i;

	//Ya que solo quiero que pille desde la posicion 1 (0 es el nombre del programa)
	i = 1;
	while (argv[i] != '\0')
	{
		char	*nombre_archivo = argv[i];

		//Leer el mapa del archivo
		char	*mapa;
		mapa = leer_mapa(nombre_archivo);

		//Mostrar el mapa
		write(1, mapa, BUFFER_SIZE);

		write(1, "\n", 1);
	
		//Mapa editado
		reemplazar_caracteres(mapa);
		write(1, mapa, BUFFER_SIZE);

		write(1, "\n", 1);

		//Crear una funcion que reemplace los caracteres "." por caracteres
		//"x" para representar el mayor cuadrado posible.

		
		//Liberar la memoria utilizada para almacenar el mapa
		free(mapa);

		i++;
	}
	return (0);
}
