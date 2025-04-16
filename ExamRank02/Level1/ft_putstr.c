
/*

Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

void	ft_putstr(char *str);

*/

#include <unistd.h>
#include <stdio.h>

void    ft_putstr_fd(char *str, int fd){
    int i = 0;

    //printf("Fd: %d\n", fd);
    if(fd >= 0){
        while(str[i])
            write(fd, &str[i++], 1);
    }   
}

void    ft_putstr(char *str){
    ft_putstr_fd(str, STDOUT_FILENO);
}

int main(){
    char *str = "hola mundo\n";
    ft_putstr(str);
}