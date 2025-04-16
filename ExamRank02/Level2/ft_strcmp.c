/*

Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);

*/
#include <stdio.h>
#include <string.h> 

int ft_strcmp(char *s1, char *s2){
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    return (s1[i] - s2[i]);

}

int main(void) {
    // Prueba 1: Cadenas iguales
    char *s1 = "abc";
    char *s2 = "abc";
    printf("Test 1: '%s' vs '%s' | strcmp: %-3d | ft_strcmp: %-3d\n", s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));

    // Prueba 2: Cadenas diferentes
    s1 = "abc";
    s2 = "abd";
    printf("Test 2: '%s' vs '%s' | strcmp: %-3d | ft_strcmp: %-3d\n", s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));

    // Prueba 3: Cadena vacía contra cadena no vacía
    s1 = "";
    s2 = "non-empty";
    printf("Test 3: '%s' vs '%s' | strcmp: %-3d | ft_strcmp: %-3d\n", s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));

    // Prueba 4: Cadenas con letras mayúsculas y minúsculas
    s1 = "Hello";
    s2 = "hello";
    printf("Test 4: '%s' vs '%s' | strcmp: %-3d | ft_strcmp: %-3d\n", s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));

    // Prueba 5: Cadenas numéricas
    s1 = "123";
    s2 = "123";
    printf("Test 5: '%s' vs '%s' | strcmp: %-3d | ft_strcmp: %-3d\n", s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));

    return 0;
}