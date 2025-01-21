/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:53:50 by niclopez          #+#    #+#             */
/*   Updated: 2025/01/21 20:01:10 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	swap_bits(unsigned char octet){
    return ((octet >> 4) | (octet << 4));
}

void print_bits(unsigned char octet) {
    int i = 7;
    while(i >= 0) {
        printf("%d", (octet >> i) & 1);
        i--;
    }

    printf("\n");
}

int main() {
    unsigned char bits = 0b01000101;
    printf("Original: ");
    print_bits(bits);

    unsigned char swapped = swap_bits(bits);
    printf("Swapped:  ");
    print_bits(swapped);

    return 0;
}