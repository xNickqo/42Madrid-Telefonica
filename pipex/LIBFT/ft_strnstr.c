/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:14:06 by niclopez          #+#    #+#             */
/*   Updated: 2024/04/03 19:54:02 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La funcion strstr() busca la palabra o coincidencia "to_find" dentro de
 * la cadena "str", si la cencuentra te devolvera la primera palabra 
 * coincidente y si no encuentra ninguna coincidencia devolera null(0)*/
char	*ft_strnstr(const char *str, char const *to_find, size_t len)
{
	size_t	str_len;
	size_t	to_find_len;
	size_t	i;
	size_t	j;

	str_len = ft_strlen(str);
	to_find_len = ft_strlen(to_find);
	i = 0;
	if (to_find_len == 0)
	{
		return ((char *)str);
	}
	while (i < str_len && i + to_find_len <= len)
	{
		j = 0;
		while (j < to_find_len && str[i + j] == to_find[j])
			j++;
		if (j == to_find_len)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void){
	char	*resultado;
	char	*str = "Por el dia de reyes me trajeron carbon";
	char	*to_find = "jose";
	resultado = ft_strnstr(str, to_find, 5);
	printf("El resutado de ft_strstr() es: %s\n", resultado);


	char	*resultadoReal;
	char	*strb = "Por el dia de reyes me trajeron carbon";
	char	*to_findb = "jose";
	resultadoReal = strnstr(strb, to_findb, 5);
	printf("El resultado de strstr() es  : %s", resultadoReal);
}*/
