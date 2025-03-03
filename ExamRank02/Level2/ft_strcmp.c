/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:45:57 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/03 23:08:43 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int ft_strcmp(char *s1, char *s2){
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    return (s1[i] - s2[i]);

}

int	main(void)
{
	char s1[100] = "abc";
	char s2[] = "aba";
	int x = ft_strcmp(s1, s2);
	printf("%d", x);
}