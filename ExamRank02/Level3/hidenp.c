#include <unistd.h>

int main(int argc, char **argv){
    if(argc == 3){
        int i = 0, j = 0;
        char *contain = argv[1];
        char *str = argv[2];

        while (contain[i] && str[j]) {
            if (contain[i] == str[j])
                i++;
            j++;
        }

        if (contain[i] == '\0')
            write(1, "1\n", 2);
        else
            write(1, "0\n", 2);
    }
    
    return 0;
}