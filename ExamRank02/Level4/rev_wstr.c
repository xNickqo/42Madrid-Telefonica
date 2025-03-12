/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_space(char c) {
    return (c == ' ' || c == '\t');
}

void ft_putstr(char *str) {
    while (*str) {
        write(1, str, 1);
        str++;
    }
}

int ft_strlen(char *str) {
    int len;
    len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

void rev_wstr(char *str) {
    int len = ft_strlen(str);
    int end = len - 1;;
    int start; // Variable para almacenar el inicio de cada palabra
    int first_word = 1;  // Bandera para evitar espacios extra entre palabras

    while (end >= 0) {
        // Saltar espacios en blanco al final y entre palabras
        while (is_space(str[end]))
            end--;

        // Buscar el inicio de la palabra
        start = end;
        while (start >= 0 && !is_space(str[start]))
            start--;
        
        // Imprimir espacio entre palabras (excepto en la primera)
        if (!first_word) 
            write(1, " ", 1);
        
        
        // Imprimir la palabra carácter por carácter
        int i = start + 1; // Ajustar al primer carácter de la palabra

        //printf("start: %c\n", str[i]);
        //printf("end: %c\n", str[end]);

        while (i <= end) {
            write(1, &str[i], 1);
            i++;
        }
        
        //printf("\n");

        // Marcar que ya imprimimos la primera palabra
        first_word = 0;

        // Mover el índice al final de la palabra anterior
        end = start - 1;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(1, "\n", 1);
        return 0;
    }
    rev_wstr(argv[1]);
    write(1, "\n", 1);
    return 0;
}
