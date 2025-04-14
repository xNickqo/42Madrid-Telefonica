/*

Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int number_len(int nbr){
    int len = 0;

    if(nbr == 0)
        len = 1;

    if(nbr < 0){
        len = 1;
        nbr = -nbr;
    }

    while(nbr > 0){
        nbr /= 10;
        len++;
    }
    return len;
}

char	*ft_itoa(int nbr){

    int n_len = number_len(nbr);
    //printf("number len: %d\n", n_len);
    
    char *str = (char *)malloc(n_len + 1);
    if(!str)
        return NULL;
    str[n_len] = '\0';

    if (nbr == 0) {
        str[0] = '0';
        return str;
    }

    if(nbr < 0){
        str[0] = '-';
        nbr = -nbr;
    }

    while (n_len > 0){
        if (nbr == 0 && n_len == 1) break;
        str[--n_len] = '0' + (nbr % 10);
        nbr/=10;
    }

    return str;
}

int main(){
    printf("%s\n", ft_itoa(123));        
    printf("%s\n", ft_itoa(-456));        
    printf("%s\n", ft_itoa(0));          
}