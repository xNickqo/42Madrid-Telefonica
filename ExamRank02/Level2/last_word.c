/*

Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/
#include <unistd.h>

int is_space(char *c){
    return (c == ' ' || c == '\t');
}

int main (int argc, char **argv){
    if (argc == 2){
        int i = 0;
        while (argv[1][i])
            i++;

        //Saltamos los espacios al final
        while (i > 0 && is_space(argv[1][i - 1]))
            i--;
        
        //Hallamos la longitud de la palabra teniendo en cuenta que i es el final de la cadena
        int end = i;
        while (i > 0 && !is_space(argv[1][i - 1]))
            i--;

        // Imprime carácter por carácter la última palabra
        while (i < end) {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}