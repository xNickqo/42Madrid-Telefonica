/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:48:25 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/04 20:09:50 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static unsigned int	number_len(int temp)
{
	unsigned int	len;

	len = 0;
	if (temp <= 0)
		len = 1;
	else
		len = 0;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int n)
{
    char			*res;
    unsigned int	len;
    unsigned int	num;

    len = number_len(n);
    res = (char *)malloc(len + 1);
    if (!res)
        return (NULL);
    res[len] = '\0';

    if (n < 0)
        num = -n;
    else
        num = n;

    while (len > 0)
    {
        res[--len] = '0' + (num % 10);
        num /= 10;
    }

    if (n < 0)
        res[0] = '-';

    return (res);
}

int main(){
    int numero = -12345;
    char *strNumero = ft_itoa(numero);

    printf("El número como string: %s\n", strNumero);
    free(strNumero);

    return 0;
}