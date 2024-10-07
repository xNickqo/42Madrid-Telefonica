/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:49:33 by niclopez          #+#    #+#             */
/*   Updated: 2024/10/04 19:08:38 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Crea una lista e introduce los valores dentro si no estan repetidos*/
void init_values(t_list **lst, int value)
{
    t_list  *new_node;
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->value == value)
			ft_error("Error: elemento duplicado.", lst, NULL);
		tmp = tmp->next;
	}
    new_node = ft_lstnew(value);
    if (new_node)
        ft_lstadd_front(lst, new_node);
}

/*Libera la memoria de reservada de una pila*/
void	free_stacks(t_list **a, t_list **b)
{
	t_list	*tmp;
	
	if (a == NULL && b == NULL)
		return ;
	if (a != NULL)
	{
        while (*a)
		{
            tmp = *a;
            *a = (*a)->next;
            free(tmp);
        }
        *a = NULL;
    }
	if (b != NULL)
	{
        while (*b)
		{
            tmp = *b;
            *b = (*b)->next;
            free(tmp);
        }
        *b = NULL;
    }
}

void	ft_error(char *message, t_list **a, t_list **b)
{
	ft_putendl_fd(message, 2);
	free_stacks(a, b);
	exit(EXIT_FAILURE);
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

void	process_args(char *argv, t_list **lst)
{
	char	**split;
	int		i;
	int		num;

	split = ft_split(argv, ' ');
	if (!split)
		ft_error("Error: fallo al dividir la cadena.", lst, NULL);
	i = 0;
	while (split[i])
	{
		num = ft_atoi(split[i]);
		init_values(lst, num);
		free(split[i]);
		i++;
	}
	free(split);
}

int main(int argc, char *argv[])
{
    int i;
    t_list *a;
    t_list *b;

    a = NULL;
    b = NULL;
	check_args(argc, argv);
	
	i = 1;
	while (i < argc)
	{
		process_args(argv[i], &a);
		i++;
	}

    if (!is_sorted(a))
    {
		if (argc <= 6)
			simple_sort(&a, &b);
		else
			quick_sort(&a, &b);
	}

	ft_printf("\n\nLista ordenada:");
    printlst(a, b);
    free_stacks(&a, &b);
    return (0);
}

/*Lista de verificación de errores
El programa debe trabajar con varios argumentos numéricos 					OK
	./push_swap 1 3 5 +9 20 -4 50 60 04 08 

El programa también funciona si recibe una sola lista de caracteres como parámetro. OK
	./push_swap "3 4 6 8 9 74 -56 +495"

El programa NO debería funcionar si encuentra otro carácter 			OK
	./push_swap 1 3 perro 35 80 -3
	./push_swap un
	./cambio de inserción 1 2 3 5 67b778 947
	.push_swap " 12 4 6 8 54fhd 4354 "
	./cambio de empuje 1--45 32
		Estos ejemplos deberían devolver "Error\n"

El programa NO debería funcionar si encuentra un número doble			OK
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