/*

Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);

*/

#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *str){
    int	resultado;
	int	signo;

	signo = 1;
	resultado = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
    
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            signo = -1;
        str++;
    }
	
	while (*str >= '0' && *str <= '9')
	{
		resultado = resultado * 10 + (*str - '0');
		str++;
	}
	return (resultado * signo);
}

int main(){

    /* char	a[] = "   --+2147483648    ";
	int	num;

	num = ft_atoi(a);
	printf("%d", num); */

	const char *tests[] = {
        "42",
        "   \t\n\r\v\f+123",
        "   -42",
        "   ---+--+1234ab567",
        "2147483647",
        "-2147483648",
        "   --+2147483648    ",
        "+-12",
        "++--+--123",
        "00000123",
        "abcd",
        "",
        NULL
    };

    for (int i = 0; tests[i] != NULL; i++) {
        int std = atoi(tests[i]);
        int mine = ft_atoi(tests[i]);
        printf("Input: %-25s | atoi: %-12d | ft_atoi: %-12d\n", tests[i], std, mine);
    }

	return 0;
}