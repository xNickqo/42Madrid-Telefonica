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

int count_words(char *str) {
    int i = 0;
    int in_word = 0;
    int count = 0;
    while (str[i]) {
        if (!is_space(str[i]) && in_word == 0) {
            in_word = 1;
            count++;
        } else if (is_space(str[i])) {
            in_word = 0;
        }
        i++;
    }
    return count;
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

void rostring(char *str) {
    int i = 0;
    int w = 0;
    int total = count_words(str);
    char **words = malloc(sizeof(char *) * (total + 1));

    // Parsear palabras
    while (str[i]) {
        while (str[i] && is_space(str[i]))
            i++;
        if (str[i]) {
            int len = word_length(&str[i]);
            words[w] = malloc_word(&str[i], len);
            w++;
            i += len;
        }
    }
    words[w] = NULL;

    // Imprimir desde la segunda palabra
    int j = 1;
    while (j < total) {
        print_str(words[j]);
        write(1, " ", 1);
        j++;
    }

    // Imprimir la primera palabra al final si existe
    if (total > 0)
        print_str(words[0]);

    // Liberar memoria
    j = 0;
    while (j < total) {
        free(words[j]);
        j++;
    }
    free(words);
}

int main(int argc, char **argv) {
    if (argc >= 2)
        rostring(argv[1]);
    write(1, "\n", 1);
    return 0;
}
