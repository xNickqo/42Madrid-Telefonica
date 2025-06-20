/*
Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>*/

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *s){
    int i = 0;
    while(s[i])
        i++;
    return i;
}

int is_space(char c) {
    return (c == ' ' || c == '\t');
}

int main(int argc, char **argv){
    char *str = argv[1];
    if(argc == 2){
        int i = ft_strlen(str);
        
        //Ignoramos los espacios del final
        while(is_space(str[i]))
            i--;

        int final = i - 1;

        //Saltamos los espacios al comienzo
        int j = 0;
        while (str[j] == ' ' || str[j] == '\t')
            j++;

        int start = j;
        int space = 0;
        while (start <= final) {
            if (is_space(str[start])) {
                if (!space) {
                    write(1, " ", 1);
                    space = 1;
                }
            } else {
                write(1, &str[start], 1);
                space = 0;
            }
            start++;
        }
    }
    write(1, "\n", 1);
    return 0;
}