/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:03:45 by niclopez          #+#    #+#             */
/*   Updated: 2025/01/21 20:48:45 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$*/


int main(int argc, char **argv){   
    if(argc == 3){
        int i = 0;
        while(argv[1][i]){
            int j = 0;
            int contador = 0;
            while(argv[2][j]){
                if(argv[2][j] == argv[1][i]){
                    contador++;
                    break;
                }
                j++;
            }

            // Verificar si el carácter ya fue procesado antes
            int z = 0;
            int ya_impreso = 0;
            while (z < i) {
                if (argv[1][z] == argv[1][i]) {
                    ya_impreso = 1;
                    break;
                }
                z++;
            }
            if (contador == 1 && ya_impreso == 0) 
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}