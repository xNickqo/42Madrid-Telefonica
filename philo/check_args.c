/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:59:08 by niclopez          #+#    #+#             */
/*   Updated: 2025/02/28 00:30:01 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *str)
{
	long	res;
	int	sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	ft_isint(const char *str)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	n = 0;
	sign = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		if (n > 214748364 || (n == 214748364
			&& ((!sign && str[i] - '0' > 7) || (sign && str[i] - '0' > 8))))
			return (0);
		else
			n = (n * 10) + str[i++] - '0';
	}
	return (1);
}

int	check_params(t_data *params, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isint(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	params->num_philo = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		params->num_philo_must_eat = ft_atoi(argv[5]);
	else
		params->num_philo_must_eat = 0;
	if (params->num_philo < 1 || params->time_to_die < 0 
        || params->time_to_eat < 0 || params->time_to_sleep < 0 
            || params->num_philo_must_eat < 0)
		return (0);
	return (1);
}
