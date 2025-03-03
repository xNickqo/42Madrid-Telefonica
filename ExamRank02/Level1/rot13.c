/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:53:56 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/03 19:52:00 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.
*/
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc == 2) {
        int i = 0;
        while (argv[1][i]) {
            char c = argv[1][i];
            
            if (c >= 'a' && c <= 'z')
                c = ((c - 'a' + 13) % 26) + 'a';
            else if (c >= 'A' && c <= 'Z')
                c = ((c - 'A' + 13) % 26) + 'A';

            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
