/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:25:34 by niclopez          #+#    #+#             */
/*   Updated: 2025/01/21 19:39:04 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.
 
'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
 
and so on.
 
Case is not changed.
 
If the number of arguments is not 1, display only a newline.
 
Examples:
 
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>*/

int main(int argc, char **argv){
    if(argc == 2){
        int i = 0;
        while (argv[1][i] != '\0') {
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z') {
                argv[1][i] = ('a' + 'z') - argv[1][i];
                write(1, &argv[1][i], 1);
            } else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') {
                argv[1][i] = ('A' + 'Z') - argv[1][i];
                write(1, &argv[1][i], 1);
            } else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}