/*

Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

char    *ft_strdup(char *src){
    char    *new_src;
    int     i;

    i = 0;
    while (src[i])
        i++;

    new_src = (char *)malloc(sizeof(char) * (i + 1));
    if(new_src == 0)
        return 0;
    
    i = 0;
    while(src[i]){
        new_src[i] = src[i];
        i++;
    }
    new_src[i] = '\0';
    
    return new_src;
}

int main() {
    char *tests[] = {
        "Hola mundo",
        "",
        "1234567890",
        "Una línea más larga con varios caracteres.",
        "Espacios     múltiples\t\t y tabs\n",
        NULL
    };

    int i = 0;
    while (tests[i]) {
        char *original = strdup(tests[i]);
        char *copy = ft_strdup(tests[i]);

        printf("Original : \"%s\"\n", original);
        printf("ft_strdup: \"%s\"\n", copy);
        printf("¿Iguales?: %s\n\n", strcmp(original, copy) == 0 ? "Sí" : "No");

        free(original);
        free(copy);
        i++;
    }

    return 0;
}