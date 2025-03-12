/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

#include <stdio.h>

int max(int *tab, unsigned int len){
    if(!tab)
        return 0;

    int max = tab[0];
    int i = len - 1;
    while (tab[i])
    {
        if(tab[i] > max)
            max = tab[i];
        i--;
    }

    return max;
}

int main(){
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {5, 4, 3, 2, 1};
    int array3[] = {-1, -2, -3, -4, -5};
    int array4[] = {7, 2, 8, 6, 4};
    int array5[] = {};

    printf("Max of array1: %d\n", max(array1, 5));
    printf("Max of array2: %d\n", max(array2, 5));
    printf("Max of array3: %d\n", max(array3, 5));
    printf("Max of array4: %d\n", max(array4, 5));
    printf("Max of array5: %d\n", max(array5, 0));
}