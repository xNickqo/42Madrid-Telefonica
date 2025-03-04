/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:29:48 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/04 19:47:23 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int ft_atoi_base(const char *str, int str_base) {
    int i = 0;
    int result = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;

    int sign = 1;
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    if (str_base < 2 || str_base > 16)
        return 0;

    while (str[i]) {
        int digit_value = 0;

        if (str[i] >= '0' && str[i] <= '9') {
            digit_value = str[i] - '0';
        }
        else if (is_alpha(str[i])) {
            if (str[i] >= 'a' && str[i] <= 'f') {
                digit_value = str[i] - 'a' + 10;
            } else if (str[i] >= 'A' && str[i] <= 'F') {
                digit_value = str[i] - 'A' + 10;
            }
        }
        result = result * str_base + digit_value;
        i++;
    }

    return sign * result;
}

int main() {
    char *str = " 1235ab";
    printf("Base 10: %d\n", ft_atoi_base(str, 10));
    printf("Base 8: %d\n", ft_atoi_base(str, 8));
    printf("Base 4: %d\n", ft_atoi_base(str, 4));
    printf("Base 16: %d\n", ft_atoi_base(str, 16));
    return 0;
}

