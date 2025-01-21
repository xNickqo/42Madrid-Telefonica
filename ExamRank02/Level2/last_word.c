/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:50:26 by niclopez          #+#    #+#             */
/*   Updated: 2025/01/21 21:15:41 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv){
    if (argc == 2){
        int i = 0;
        while (argv[1][i])
            i++;

        //Saltamos los espacios al final
        while (i > 0 && (argv[1][i - 1] == ' ' || argv[1][i - 1] == '\t'))
            i--;
        
        //Hallamos la longitud de la palabra teniendo en cuenta que i es el final de la cadena
        int end = i;
        while (i > 0 && argv[1][i - 1] != ' ' && argv[1][i - 1] != '\t')
            i--;

        // Imprime carácter por carácter la última palabra
        while (i < end) {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}