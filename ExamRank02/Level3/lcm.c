#include <stdio.h>
//minimo comun multiplo
int lcm(unsigned int num1, unsigned int num2){
    if(num1 <= 0 || num2 <= 0)
        return 0;
    
    int i = 2;
    while(i <= num1 * num2){
        if(i % num1 == 0 && i % num2 == 0)
            return i;
        i++;
    }
    return num1 * num2;
}

int main(){
    printf("%d\n", lcm(7, 14));
}