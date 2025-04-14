#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_space(char c) {
    return (c == ' ' || c == '\t');
}

int word_length(char *str) {
    int i = 0;
    while (str[i] && !is_space(str[i]))
        i++;
    return i;
}

int count_words(char *str){
    int i = 0;
    int in_word = 0;
    int word = 0;
    while (str[i]){
        if(in_word == 0 && !is_space(str[i]))
        {
            word++;
            in_word = 1;
        }
        else if (is_space(str[i]) && in_word == 1) {
            in_word = 0;
        }
        i++;
    }
    return word;
}

char *malloc_word(char *str, int len) {
    char *word = malloc(len + 1);
    int i = 0;
    while (i < len) {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return word;
}

void print_str(char *str) {
    int i = 0;
    while (str[i]) {
        write(1, &str[i], 1);
        i++;
    }
}

void rev_wstr(char *str) {
    int i = 0;
    int w = 0;
    int total = count_words(str);
    //printf("Total words: %d\n", total);

    char **words = malloc(sizeof(char *) * (total + 1));

    while (str[i]) {

        while (str[i] && is_space(str[i]))
            i++;
        
        if (str[i]) {  // Si no es el final de la cadena
            int len = word_length(&str[i]);

            words[w] = malloc_word(&str[i], len);
            //printf("%s\n", words[w]);

            w++;
            i += len;
        }
    }
    words[w] = NULL;

    // Print in reverse
    w = total - 1;
    while (w >= 0) {
        print_str(words[w]);
        if (w != 0)
            write(1, " ", 1);

        free(words[w]);
        w--;
    }
    free(words);
}

int main(int argc, char **argv) {
    if (argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n", 1);
    return 0;
}
