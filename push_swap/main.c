/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:49:33 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/02 23:33:47 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	a;
	t_stack b;
	a.last = NULL;
	b.last = NULL;

    if (argc < 2)
	{
		printf("Error. Debes inrocudir minimo un argumento");
        return (1);
	}
    
	int	i = 1;
	while (i < argc)
	{
		int	num = ft_atoi(argv[i]);
		push(&a, num);
		i++;
	}

	p(&a, &b);
	s(&a);

	printlst(&a);
	printlst(&b);

	free_stack(&a);
	free_stack(&b);
    
    return (0);
}

/*Estrategias o Algoritmos Comunes
		Hay varias estrategias que puedes seguir para desarrollar tu solución. Aquí 
		te explico algunas de las más comunes:

		1. Sort Simple (para pocos elementos)
		Descripción: Para listas pequeñas (por ejemplo, 3 a 5 elementos), 
		puedes simplemente enumerar todos los posibles órdenes y programar 
		una secuencia de movimientos para cada posible orden inicial.
		Ventajas: Muy eficiente en términos de número de operaciones porque 
		está específicamente diseñada para estos casos.
		Desventajas: No es escalable para listas grandes.

		2. Insertion Sort
		Descripción: Similar al algoritmo de inserción clásico. Mantienes una 
		pila a donde intentas ordenar elementos mientras empujas los elementos menores a 
		la pila b. Luego, los devuelves a a en el orden correcto.
		Ventajas: Relativamente sencillo de implementar.
		Desventajas: Puede no ser óptimo en términos de número de operaciones 
		para listas grandes.

		3. Quick Sort (versión simplificada)
		Descripción: Elige un pivote y divide la pila a en dos subpilas, moviendo elementos 
		mayores al pivote a la pila b. Recursivamente, ordenas estas subpilas y luego 
		las combinas.
		Ventajas: Buen rendimiento para listas de tamaño mediano a grande.
		Desventajas: Puede ser más complejo de implementar y optimizar.

		4. Radix Sort (versión binaria)
		Descripción: Trabaja sobre los bits individuales de los números, dividiendo 
		los elementos en subpilas b basadas en el bit significativo actual y luego 
		moviéndolos de regreso a a.
		Ventajas: Es particularmente eficiente para listas grandes y con números 
		que tienen un rango amplio.
		Desventajas: Puede ser más difícil de comprender e implementar, pero es una 
		de las mejores en términos de número de operaciones para listas grandes.
*/