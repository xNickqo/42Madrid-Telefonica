/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:44:30 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/18 17:53:09 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.
If the number is a multiple of 3, it prints 'fizz' instead.
If the number is a multiple of 5, it prints 'buzz' instead.
If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.*/

#include <unistd.h>

void write_num(int num){
    char str[10] = "0123456789";
    if(num > 9)
        write_num(num / 10);
    write(1, &str[num % 10], 1);
}

int main (int argc, char **argv){
    int i = 1;
    while (i <= 100){
        if(i % 3 == 0)
            write(1,"fizz",4);
        else if(i % 5 == 0)
            write(1,"buzz",4);
        else if(i % 15 == 0)
            write(1,"fizzbuzz",8);
        else
            write_num(i);
        i++;
        write(1, "\n", 1);
    }
}