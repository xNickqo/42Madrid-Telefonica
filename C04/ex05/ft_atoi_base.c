/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:22:16 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/21 17:58:12 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(char *str, char *base)
{
	int	resultado;
	int	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (len <= 1)
		return (0);
	resultado = 0;
	while (*str >= '0' && *str <= '9')
	{
		resultado = resultado * 10 + (*str - '0');
		str++;
	}
	return (resultado);
}
/*
int	main(void)
{
	char	str[] = "1234";
	char	base[] = "01";
	int 	resultado;

	resultado = ft_atoi_base(str, base);
	printf("%d", resultado);
}*/
