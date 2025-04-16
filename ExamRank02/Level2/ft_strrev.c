/*

Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);

*/

#include <stdio.h>

void ft_swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

char    *ft_strrev(char *str)
{
	int i = 0;
	int len = 0;

	while (str[len])
		len++;

	len = len - 1; //Evitamos '\0'
	while (i < len)
	{
		ft_swap(&str[i], &str[len]);
		i++;
		len--;
	}
	return (str);
}

int	main(void)
{
	char s[] = "Hello World";
	ft_strrev(s);
	printf("%s\n", s);
	return (0);
}