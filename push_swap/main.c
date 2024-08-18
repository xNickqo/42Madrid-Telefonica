/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:49:33 by niclopez          #+#    #+#             */
/*   Updated: 2024/08/18 20:56:38 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
	{
		printf("Error. Debes inrocudir minimo un argumento");
        return (1);
	}
    
	//Convertir argumentos a numeros y almacenar en la pila 'a'
	int	i = 1;
	while (i < argc)
	{
		int	num = atoi(argv[i]);
		printf("%d\n", num);
		i++;
	}

	//Estructura de datos para las pilas y cargaras 'a' con los numeros

	//Llamaras a la funcion que implementara el algoritmo de ordenamiento
	push_swap(a);

    
    return (0);
}