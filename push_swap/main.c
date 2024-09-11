/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:49:33 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/11 20:24:41 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Crea una lista e introduce los valores dentro*/
void init_values(t_list **lst, int value)
{
    t_list  *new_node;

    new_node = ft_lstnew(value);
    if (new_node)
        ft_lstadd_front(lst, new_node);
}

/*Libera la memoria de reservada de una pila*/
void	free_stack(t_list **lst)
{
	t_list	*list;
	t_list	*tmp;

	list = *lst;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	*lst = NULL;
}


int main(int argc, char *argv[])
{
	int		i;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

    if (argc < 2)
		return (-1);
	
	i = 1;
	while (i < argc)
	{
		int	num = ft_atoi(argv[i]);
		init_values(&a, num);
		i++;
	}
	pa(&a, &b);
	pa(&a, &b);
	/* rra(&a);
	pa(&a, &b); */

	printList(a);
	printList(b);

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