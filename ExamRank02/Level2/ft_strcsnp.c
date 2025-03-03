/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsnp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:20:28 by niclopez          #+#    #+#             */
/*   Updated: 2025/03/03 23:22:05 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcspn(const char *s, const char *reject) {
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return i;
            j++;
        }
        i++;
    }
    return i;
}