/*

Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$

*/

#include <unistd.h>

void putnbr_base(int n){
    char *hex = "0123456789abcdef";

    if(n >= 16)
        putnbr_base(n / 16);
    write(1, &hex[n % 16], 1);
    
}

int ft_atoi(char *str){
    int res = 0;
    int i = 0;
    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    
    int sign = 1;
    if(str[i] == '-' || str[i] == '+'){
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    
    while(str[i] >= '0' && str[i] <= '9'){
        res = res * 10 + (str[i] - '0');
        i++;
    }

    return res * sign;
}

int main(int ac, char **av) {
    if (ac == 2) {
        if (!*av[1] || av[1][0] == '-')
            return write(1, "\n", 1);
        putnbr_base(ft_atoi(av[1]));
    }
    write(1, "\n", 1);
    return 0;
}