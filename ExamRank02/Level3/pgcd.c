/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

//Maximo comun denominador

#include <stdio.h>
#include <stdlib.h>

// Función para calcular el GCD (Máximo Común Divisor) usando el algoritmo de Euclides
int pgcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(int argc, char **argv) {
    if (argc == 3) {
        // Usamos malloc para almacenar los números de entrada
        int *num1 = (int *)malloc(sizeof(int));
        int *num2 = (int *)malloc(sizeof(int));
        
        if (num1 == NULL || num2 == NULL) 
            return 1;
        
        *num1 = atoi(argv[1]);
        *num2 = atoi(argv[2]);
        
        if (*num1 > 0 && *num2 > 0) {
            printf("%d\n", pgcd(*num1, *num2));
        }
        
        free(num1);
        free(num2);
    } else {
        printf("\n");
    }
    
    return 0;
}


/* void	ft_pgcd(int a, int b)
{
	int i;
	int gcd;

	i = 1;
	gcd = 0;
	while (i < a && i < b)
	{
		if (a % i == 0 && b % i == 0)
			gcd = i;
		i++;
	}
	printf("%d", gcd);
}

int main(int argc, char **argv){
    if(argc == 3){
        ft_pgcd(atoi(argv[1]), atoi(argv[2]));
    }
    printf("\n");
    return 0;
}
 */