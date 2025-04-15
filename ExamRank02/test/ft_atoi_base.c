/*

Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);

*/

#include <stdio.h>

int is_space(char c){
    return (c == ' ' || (c >= 9 && c <=13));
}

int	ft_atoi_base(const char *str, int str_base){
    int i = 0;
    while(is_space(str[i]))
        i++;

    int sign = 1;
    if(str[i] == '-'){
        sign = -1;
        i++;
    } else if(str[i] == '+'){
        i++;
    }

    int res = 0;
    int digit_value = 0;
    while (str[i]){
        char c = str[i];

        if (c >= '0' && c <= '9')
            digit_value = c - '0';
        else if (c >= 'a' && c <= 'f')
            digit_value = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F')
            digit_value = c - 'A' + 10;
        else
            break;

        if (digit_value >= str_base)
            break;

        //printf("Procesando '%c': valor = %d, acumulado = %d -> ", c, digit_value, res);
        res = res * str_base + digit_value;
        //printf("%d\n", res);
        i++;
    }
    return res * sign;
}

int main(){
    char *str = " 1235ab";
    printf("Base 10: %d\n", ft_atoi_base(str, 10));
    printf("Base 8: %d\n", ft_atoi_base(str, 8));
    printf("Base 4: %d\n", ft_atoi_base(str, 4));
    printf("Base 16: %d\n", ft_atoi_base(str, 16));
    return 0;
}

