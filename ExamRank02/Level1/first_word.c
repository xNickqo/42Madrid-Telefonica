/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:55:42 by niclopez          #+#    #+#             */
/*   Updated: 2024/12/18 18:02:43 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
If the number of parameters is not 1, or if there are no words, simply display
a newline.
Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>*/

#include <unistd.h>

int main(int argc, char **argv){
    if(argc == 2){
        int i = 0;
        while(argv[1][i] == 9 || argv[1][i] == 32)
            i++;
        while(argv[1][i])
        {
            if(argv[1][i] == 9 || argv[1][i] == 32)
                break;
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}