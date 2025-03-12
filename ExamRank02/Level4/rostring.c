/*

Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

*/

#include <unistd.h>
#include <stdlib.h>

int is_space(char c) {
    return (c == ' ' || c == '\t');
}

void rostring(char *str) {
    int i = 0;
    int start = 0;
    int end = 0;
    int first_word_found = 0;
    
    // Saltar espacios iniciales
    while (str[i] && is_space(str[i]))
        i++;
    
    start = i; // Inicio de la primera palabra
    while (str[i] && !is_space(str[i]))
        i++;
    end = i; // Fin de la primera palabra
    
    // Saltar espacios después de la primera palabra
    while (str[i] && is_space(str[i]))
        i++;
    
    // Imprimir el resto de las palabras
    while (str[i]) {
        if (!is_space(str[i])) {
            if (first_word_found)
                write(1, " ", 1);
            while (str[i] && !is_space(str[i])) {
                write(1, &str[i], 1);
                i++;
            }
            first_word_found = 1;
        }
        else {
            i++;
        }
    }
    
    // Imprimir la primera palabra al final si existe
    if (start < end) {
        if (first_word_found)
            write(1, " ", 1);
        write(1, &str[start], end - start);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        write(1, "\n", 1);
        return 0;
    }
    rostring(argv[1]);
    write(1, "\n", 1);
    return 0;
}
