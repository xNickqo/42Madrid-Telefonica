/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>
#include <stdio.h>

int ft_count(int start, int end){
    int len = 0;

    if(start < end){
        while (start <= end){
            start++;
            len++;
        }
    } else {
        while (start >= end){
            end++;
            len++;
        }
    }
    
    return len;
}

int *ft_range(int start, int end){
    int len = ft_count(start, end);
    int *arrayInt = (int *)malloc(sizeof(int) * len);
    if (!arrayInt)
        return 0;

    int i = 0;
    while (i < len){
        arrayInt[i] = start;

        if (start < end)
            start++;
        else
            start--;
        i++;
    }

    return arrayInt;
}


int main(){
    int *arrayInt = ft_range(0, -3);
    int i = 0;
    while (i < ft_count(0, -3))
    {
        printf("%d ", arrayInt[i]);
        i++;
    }
    printf("\n");
}