/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:25:43 by niclopez          #+#    #+#             */
/*   Updated: 2025/02/28 00:00:12 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct l_philo
{
    int num_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_philo_must_eat;
    pthread_mutex_t *forks;
}		t_data;

typedef struct s_philo {
    int id;
    int meals_eaten;
    t_data *data;
    pthread_t thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
}   t_philo;

int	check_params(t_data *params, int argc, char *argv[]);
int	ft_isint(const char *str);
long	ft_atoi(const char *str);

#endif