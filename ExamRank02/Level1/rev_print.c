/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:18:04 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/03 17:53:29 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv){
    if(argc == 2){
        int i = 0;
        while(argv[1][i] != '\0')
            i++;
        int len = i - 1;
        while(len >= 0){
            write(1, &argv[1][len], 1);
            len--;
        }
    }
    write(1, "\n", 1);
}