/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:53:50 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/03 22:45:04 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_atoi(const char *str){
    int	resultado;
	int	signo;

	signo = 1;
	resultado = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
    int signo_count = 0;
    while (*str == '-' || *str == '+') {
        if (*str == '-') {
            signo_count++;
        }
        str++;
    }
    if (signo_count % 2 != 0) {
        signo = -1;
    }
	while (*str >= '0' && *str <= '9')
	{
		resultado = resultado * 10 + (*str - '0');
		str++;
	}
	return (resultado * signo);
}

int main(){
    char	a[] = "   --+2147483648    ";
	int	num;

	num = ft_atoi(a);
	printf("%d", num);
}