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

int is_space(char c) {
    return (c == ' ') || (c == '\t');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int ft_atoi_base(const char *str, int str_base) {
    if (str_base < 2 || str_base > 16)
        return 0;
        
    int i = 0;
    int result = 0;

    while (is_space(str[i]))
        i++;

    int sign = 1;
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    while (str[i]) {
        int digit_value = 0;

        if (is_digit(str[i])) {
            digit_value = str[i] - '0';
        } else if (str[i] >= 'a' && str[i] <= 'f') {
            digit_value = str[i] - 'a' + 10;
        } else if (str[i] >= 'A' && str[i] <= 'F') {
            digit_value = str[i] - 'A' + 10;
        }
        //printf("Carácter: %c -> Valor: %d\n", str[i], digit_value);
        
        result = result * str_base + digit_value;
        //printf("Resultado acumulado: %d\n", result);
        i++;
    }

    return sign * result;
}

int main() {
    char *str = " 1235ab";
    printf("Base 10: %d\n", ft_atoi_base(str, 10));
    printf("Base 8: %d\n", ft_atoi_base(str, 8));
    printf("Base 4: %d\n", ft_atoi_base(str, 4));
    printf("Base 16: %d\n", ft_atoi_base(str, 16));
    return 0;
}

