/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/
#include <stdio.h>

int is_power_of_2(unsigned int n) {
    if (n == 0)
        return 0; 

	unsigned int limit = 1; 
    while (n > limit) {
        if (n % 2 != 0)
            return 0;
        n /= 2;
    }
    return 1;
}

int	main(void)
{
	printf("0 es potencia de dos?: %d\n", is_power_of_2(0));
	printf("1 es potencia de dos?: %d\n", is_power_of_2(1));
	printf("2 es potencia de dos?: %d\n", is_power_of_2(2));
	printf("4 es potencia de dos?: %d\n", is_power_of_2(4));
	printf("6 es potencia de dos?: %d\n", is_power_of_2(6));
	printf("8 es potencia de dos?: %d\n", is_power_of_2(8));
	printf("32 es potencia de dos?: %d\n", is_power_of_2(32));
	printf("42 es potencia de dos?: %d\n", is_power_of_2(42));
	printf("67 es potencia de dos?: %d\n", is_power_of_2(67));
	printf("124 es potencia de dos?: %d\n", is_power_of_2(124));
	printf("256 es potencia de dos?: %d\n", is_power_of_2(256));
	return (0);
}