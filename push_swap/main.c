/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:49:33 by niclopez          #+#    #+#             */
/*   Updated: 2024/09/15 18:54:19 by niclopez         ###   ########.fr       */
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

    while (ft_lstsize(*a) > 3)
    {
        min = get_min_pos(*a);
        move_to_top(a, min);
        pb(a, b);
		printList(*a, *b);
    }
    small_sort(a);

    while (ft_lstsize(*b) > 0)
	{
        pa(a, b);
		printList(*a, *b);
	}
}


/* Mover los elementos menores que el pivote a la pila 'b' 
	y mantener los mayores en la 'a'*/
int partition(t_list **a, t_list **b, int pivot)
{
    int size;
    int pushed;
    int moved;

    size = ft_lstsize(*a);
    pushed = 0;
    moved = 0;

    while (moved < size)
    {
        if ((*a)->value < pivot)
        {
            pb(a, b);
            pushed++;
        }
        else
        {
            ra(a);
        }
        moved++;
		printList(*a, *b);
		ft_printf("Pivote: %d, Elemento actual: %d\n", pivot, (*a)->value);
    }
    return (pushed);
}

/* Selecciona un pivote aleatorio de la lista */
int get_random_pivot(t_list *a)
{
    int size = ft_lstsize(a);
    int random_index = rand() % size;
    t_list *tmp = a;

    for (int i = 0; i < random_index; i++)
	{
        tmp = tmp->next;
    }
    return tmp->value;
}

/* Calcula la media de los valores en la lista */
int	get_pivot_mean(t_list *a)
{
	int	size;
	int	pivot;
	t_list	*tmp;
	int	sum;

	sum = 0;
	size = ft_lstsize(a);
	if(size <= 1)
		return (0);

	tmp = a;
	while (tmp)
	{
		sum += tmp->value;
		tmp = tmp->next;
	}
	pivot = sum / size;
	return (pivot);
}

/* selecciona tres elementos de la lista (el primero, el del medio y el último) y 
	devuelve la mediana de estos tres elementos como el pivote */
int get_pivot_median_of_three(t_list *a)
{
    t_list *first, *middle, *last;
    int size = ft_lstsize(a);
    int values[3];
	int	i;

    if (size < 3)
        return get_pivot_mean(a);

    first = a;
    middle = a;
    last = a;

    // Avanzar `middle` a la mitad de la lista.
	i = 0;
    while (i < size / 2)
	{
        middle = middle->next;
		i++;
    }
	
    // Avanzar `last` al final de la lista.
    last = ft_lstlast(a);

    // Recoge los valores.
    values[0] = first->value;
    values[1] = middle->value;
    values[2] = last->value;

    // Encuentra la mediana.
    if ((values[0] > values[1]) != (values[0] > values[2])) return values[0];
    if ((values[1] > values[0]) != (values[1] > values[2])) return values[1];
    return values[2];
}

/* Ordena recursivamente ambas pilas utilizando partition */
void quick_sort(t_list **a, t_list **b)
{
    int pivot;
    int pushed;

    if (is_sorted(*a) || ft_lstsize(*a) <= 1)
        return;

    if (ft_lstsize(*a) > 50)
		pivot = get_random_pivot(*a);
	else
		pivot = get_pivot_median_of_three(*a);

    pushed = partition(a, b, pivot);

	if (ft_lstsize(*a) > 1)
    	quick_sort(a, b);

	if (ft_lstsize(*b) > 1)
    	quick_sort(b, a);

    while (pushed > 0)
    {
        pa(a, b);
        pushed--;
    }
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
	
    if (!is_sorted(a))
    {
		if (argc <= 6)
			simple_sort(&a, &b);
		else
			quick_sort(&a, &b);
	}

    printList(a, b);

    free_stack(&a);
    free_stack(&b);
    return (0);
}


/*Lista de verificación de errores
El programa debe trabajar con varios argumentos numéricos
	./push_swap 1 3 5 +9 20 -4 50 60 04 08

El programa también funciona si recibe una sola lista de caracteres como parámetro.
	./push_swap "3 4 6 8 9 74 -56 +495"

El programa NO debería funcionar si encuentra otro carácter
	./push_swap 1 3 perro 35 80 -3
	./push_swap un
	./cambio de inserción 1 2 3 5 67b778 947
	.push_swap " 12 4 6 8 54fhd 4354 "
	./cambio de empuje 1--45 32
		Estos ejemplos deberían devolver "Error\n"

El programa NO debería funcionar si encuentra un número doble
	./push_swap 1 3 58 9 3
	./push_swap 3 03
	./push_swap " 49 128 50 38 49"
		Estos ejemplos deberían devolver "Error\n"
	./push_swap "95 99 -9 10 9"
		Este ejemplo debería funcionar porque -9 y 9 no son iguales

El programa debería funcionar con INT MAX y INT MIN
	./push_swap 2147483647 2 4 7
	./push_swap 99 -2147483648 23 545
	./push_swap "2147483647 843 56544 24394"
		Estos ejemplos deberían funcionar y ordenar tu lista.
	./cambio de empuje 54867543867438 3
	./push_swap-2147483647765 4 5
	./push_swap "214748364748385 28 47 29"
		Estos ejemplos deberían devolver "Error\n"

No se ha especificado nada cuando se mezclan cadenas y enteros. 
Depende de usted lo que desee hacer.
	./push_swap "1 2 4 3" 76 90 "348 05
*/