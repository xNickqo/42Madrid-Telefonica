/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:54:57 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/04 19:28:23 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    char *str = argv[1];
    if(argc == 2){
        int i = 0;
        while(str[i])
            i++;
        while(str[i] == ' ' || str[i] == '\t')
            i--;
        int final = i - 1;

        int space = 0;
        int j = 0;
        while (str[j] == ' ' || str[j] == '\t')
            j++;
        while (j <= final) {
            if (str[j] == ' ' || str[j] == '\t') {
                if (!space) {
                    write(1, " ", 1);
                    space = 1;
                }
            } else {
                write(1, &str[j], 1);
                space = 0;
            }
            j++;
        }
    }
    write(1, "\n", 1);
    return 0;
}