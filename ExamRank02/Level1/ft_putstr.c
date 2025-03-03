/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:29:03 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/03 17:48:13 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_putstr_fd(char *str, int fd){
    int i = 0;

    printf("Fd: %d\n", fd);
    if(fd >= 0){
        while(str[i])
            write(fd, &str[i++], 1);
    }   
}

void    ft_putstr(char *str){
    ft_putstr_fd(str, STDOUT_FILENO);
}

/* int main(){
    char *str = "hola mundo";
    ft_putstr(str);
} */