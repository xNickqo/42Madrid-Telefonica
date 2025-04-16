/*

Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>


/*
** ft_strcspn:
** Recorre la cadena 's' carácter por carácter.
** Por cada carácter de 's', compara si coincide con alguno de los caracteres de 'reject'.
** Si encuentra un carácter en 's' que también está en 'reject', devuelve la posición (índice) de ese carácter en 's'.
** Si ningún carácter de 's' está en 'reject', devuelve la longitud de 's'.
*/
size_t ft_strcspn(const char *s, const char *reject) {
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return i;
            j++;
        }
        i++;
    }
    return i;
}


int main(void) {
    const char *s, *reject;

    // Test 1
    s = "hello world";
    reject = " ";
    printf("Test 1:\n");
    printf("Input: \"%s\" | Reject: \"%s\"\n", s, reject);
    printf("strcspn: %zu | ft_strcspn: %zu\n\n", strcspn(s, reject), ft_strcspn(s, reject));

    // Test 2
    s = "abcdef";
    reject = "x";
    printf("Test 2:\n");
    printf("Input: \"%s\" | Reject: \"%s\"\n", s, reject);
    printf("strcspn: %zu | ft_strcspn: %zu\n\n", strcspn(s, reject), ft_strcspn(s, reject));

    // Test 3
    s = "123456789";
    reject = "5";
    printf("Test 3:\n");
    printf("Input: \"%s\" | Reject: \"%s\"\n", s, reject);
    printf("strcspn: %zu | ft_strcspn: %zu\n\n", strcspn(s, reject), ft_strcspn(s, reject));

    // Test 4
    s = "openai";
    reject = "aeiou";
    printf("Test 4:\n");
    printf("Input: \"%s\" | Reject: \"%s\"\n", s, reject);
    printf("strcspn: %zu | ft_strcspn: %zu\n\n", strcspn(s, reject), ft_strcspn(s, reject));

    // Test 5
    s = "";
    reject = "abc";
    printf("Test 5:\n");
    printf("Input: \"%s\" | Reject: \"%s\"\n", s, reject);
    printf("strcspn: %zu | ft_strcspn: %zu\n\n", strcspn(s, reject), ft_strcspn(s, reject));

    return 0;
}