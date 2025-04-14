/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:37:48 by niclopez          #+#    #+#             */
/*   Updated: 2025/04/14 20:31:28 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/

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

