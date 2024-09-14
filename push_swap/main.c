/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:49:33 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/14 20:23:46 by niclopez         ###   ########.fr       */
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

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

/* Obtiene la poscion del numero mas pequeño de la lista*/
int	get_min_pos(t_list *a)
{
	t_list	*tmp;
	int		min_value;
	int		min_pos;
	int		i;

	tmp = a;
	min_value = tmp->value;
	min_pos = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->value < min_value)
		{
			min_value = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}


/* Mueve el valor a la parte superior de la pila a usando las operaciones 'ra'
o 'rra', dependiendo de que tan cerca este de la parte superior o inferior de la pila*/
void	move_to_top(t_list **a, int pos)
{
	int	size;
	int	i;
	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		i = 0;
		while (i < pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - pos)
		{
			rra(a);
			i++;
		}
	}
}

/* Esta funcion maneja los cassos de cuando tienes 2 o 3 elementos en la pila 'a'*/
void small_sort(t_list **a)
{
    int first;
    int second;
    int third;

    if (is_sorted(*a))
        return;

    if (ft_lstsize(*a) == 2)
    {
        if ((*a)->value > (*a)->next->value)
            sa(a);
    }
    else if (ft_lstsize(*a) == 3)
    {
        first = (*a)->value;
        second = (*a)->next->value;
        third = (*a)->next->next->value;

        if (first > second && second < third && first < third)
            sa(a);  // Caso 3 2 1
        else if (first > second && second > third && first > third)
        {
            sa(a);
            rra(a); // Caso 2 3 1
        }
        else if (first > second && second < third && first > third)
            ra(a); // Caso 2 3 1
        else if (first < second && second > third && first < third)
        {
            sa(a);
            ra(a); // Caso 1 3 2
        }
        else if (first < second && second > third && first > third)
            rra(a); // Caso 3 1 2
    }
}



/* listas pequeñas entre 5 y 2 elementos 
	Identidicar el numero mas pequeño y colocarlo en la pila 'b', luego continuar con el resto
	hasta que 'a' este ordenado. y pasar los elementos de 'b' a 'a'*/
void simple_sort(t_list **a, t_list **b)
{
    int min;

    // Mueve elementos de `a` a `b` hasta que `a` tenga 3 o menos elementos
    while (ft_lstsize(*a) > 3)
    {
        min = get_min_pos(*a);
        move_to_top(a, min);
        pb(a, b); // Asegúrate de que `pb` toma `a` como primer argumento
    }

    // Ordena los 3 elementos restantes en `a`
    small_sort(a);

    // Mueve los elementos de `b` de vuelta a `a`
    while (ft_lstsize(*b) > 0)
        pa(a, b); // Asegúrate de que `pa` toma `a` como primer argumento
}



int main(int argc, char *argv[])
{
    int i;
    t_list *a;
    t_list *b;

    a = NULL;
    b = NULL;

    if (argc < 2)
        return (-1);

    i = 1;
    while (i < argc)
    {
        int num = ft_atoi(argv[i]);
        init_values(&a, num);
        i++;
    }

    // Solo llama a `simple_sort` si la lista no está ordenada
    if (!is_sorted(a))
        simple_sort(&a, &b);

    printList(a, b);
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