/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:37:48 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/04 18:49:04 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

void	ft_putnbr(int n)
{
	if (n / 10 != 0)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int ft_atoi(char *s) {
    int i = 0;
    int res = 0;
    while (s[i]){
        res = res * 10 + (s[i++] - '0');
    }
    return res;
}

int ft_is_prime(int n) {
    if (n < 2)
        return 0;
    
    int i = 2;
    while (i < n) {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    int sum = 0;
    int n = ft_atoi(argv[1]);
    
    if (argc == 2)
    {
        int i = 2;
        while (i <= n)
        {
            if (ft_is_prime(i)) 
                sum += i;
            i++;
        }
        ft_putnbr(sum);
    }
    else
    {
        write(1, "0", 1);
    }
    
    write(1, "\n", 1);
    
    return 0;
}

