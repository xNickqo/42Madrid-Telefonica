/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and 
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)
  
  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/

#include <stdio.h>

// Función para calcular el GCD (Máximo Común Divisor) usando el algoritmo de Euclides
unsigned int gcd(unsigned int a, unsigned int b) {
    printf("Iniciando GCD de %u y %u\n", a, b);
    
    // Bucle de Euclides
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;

        // Mensajes de depuración para ver el progreso
        printf("Nuevo paso: a = %u, b = %u (resto de %u %% %u)\n", a, b, a, temp);
    }

    // El último valor de a es el GCD
    printf("El GCD es: %u\n", a);
    return a;
}

// Función para calcular el LCM (Mínimo Común Múltiplo) usando la fórmula LCM = |a * b| / GCD(a, b)
unsigned int lcm(unsigned int a, unsigned int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    // Calculamos el LCM usando la fórmula
    return (a * b) / gcd(a, b);
}

int main() {
    // Probamos la función con algunos ejemplos
    printf("LCM(7, 14) = %u\n", lcm(7, 14));  // Debería devolver 14
    printf("LCM(12, 18) = %u\n", lcm(12, 18)); // Debería devolver 36
    printf("LCM(0, 5) = %u\n", lcm(0, 5));    // Debería devolver 0
    printf("LCM(15, 25) = %u\n", lcm(15, 25)); // Debería devolver 75
    return 0;
}




//minimo comun multiplo
/* int lcm(unsigned int num1, unsigned int num2){
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
} */