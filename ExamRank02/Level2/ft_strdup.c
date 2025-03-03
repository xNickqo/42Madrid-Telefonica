/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:23:12 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/03 23:33:15 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src){
    char    *new_src;
    int     i;

    i = 0;
    while (src[i])
        i++;

    new_src = (char *)malloc(sizeof(char) * i + 1);
    if(new_src == 0)
        return 0;
    
    i = 0;
    while(src[i]){
        new_src[i] = src[i];
        i++;
    }
    new_src[i] = '\0';
    
    return new_src;
}

int main(){
    char *str = "hola mundo";

    char *new_str = ft_strdup(str);
    printf("Esto es una copia de la cadena original: %s\n", new_str);
}