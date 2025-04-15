/*

Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>

*/

#include <unistd.h>

int is_alpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int is_space(char c) {
    return (c == ' ' || (c >= 9 && c <= 13));
}

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

char to_upper(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

void str_capitalizer(char *str) {
    int i = 0;
    int first_letter = 1;

    while (str[i]) {
        if (is_alpha(str[i])) {
            if (first_letter)
                str[i] = to_upper(str[i]);
            else
                str[i] = to_lower(str[i]); 
            first_letter = 0; // Ya no estamos al inicio de una palabra
        } else {
            if (is_space(str[i]))
                first_letter = 1;
            else
                first_letter = 0; 
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv) {
    int i = 1;

    if(argc >= 2){
        while (i < argc) {
            str_capitalize(argv[i]);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
