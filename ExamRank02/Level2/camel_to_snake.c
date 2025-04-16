
#include <unistd.h>

/*Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$*/

int main(int argc, char **argv){
    if(argc == 2){
        int i = 0;
        while(argv[1][i]){
            if(argv[1][i] >= 'A' && argv[1][i] <= 'Z'){
                write(1, "_", 1);
                argv[1][i] += 32;
                write(1, &argv[1][i], 1);
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}