/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:14:06 by niclopez          #+#    #+#             */
/*   Updated: 2024/03/21 15:04:46 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La funcion strstr() busca la palabra o coincidencia "to_find" dentro de
 * la cadena "str", si la cencuentra te devolvera la primera palabra 
 * coincidente y si no encuentra ninguna coincidencia devolera null(0)*/
char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
/*
int	main(void){
	char	*resultado;
	char	*str = "Por el dia de reyes me trajeron carbon";
	char	*to_find = "jose";
	resultado = ft_strstr(str, to_find);
	printf("El resutado de ft_strstr() es: %s\n", resultado);


	char	*resultadoReal;
	char	*strb = "Por el dia de reyes me trajeron carbon";
	char	*to_findb = "jose";
	resultadoReal = strstr(strb, to_findb);
	printf("El resultado de strstr() es  : %s", resultadoReal);
}*/
