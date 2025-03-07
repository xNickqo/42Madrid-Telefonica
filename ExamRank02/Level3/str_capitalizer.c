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
            first_letter = is_space(str[i]);  // Si es espacio, la siguiente letra es inicio de palabra
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (i > 1)
                write(1, " ", 1);
            str_capitalizer(argv[i]);
        }
    }
    write(1, "\n", 1);
    return 0;
}
