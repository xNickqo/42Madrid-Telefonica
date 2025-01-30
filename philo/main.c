/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:29:40 by niclopez          #+#    #+#             */
/*   Updated: 2025/01/30 23:15:14 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* FUNCIONES AUTORIZADAS */
/*  
memset, 
printf, 
malloc, 
free, 
write,
usleep, 
gettimeofday, 
pthread_create,
pthread_detach, 
pthread_join, 
pthread_mutex_init,
pthread_mutex_destroy, 
pthread_mutex_lock,
pthread_mutex_unlock
*/

#include "philo.h"

struct timeval start_time;

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

void print_status(int id, char *status) {
    float timestamp = get_time();
    printf("%.3fms Philosopher [%d] %s\n", timestamp, id + 1, status);
}

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

void *philosopher_routine(void *arg) {
    t_philo *philo = (t_philo *)arg;
    
    while (1) {
        printf("Filósofo %d está pensando...\n", philo->id + 1);
        usleep(5000);

        // Tomar cubiertos (bloquear mutexes)
        pthread_mutex_lock(philo->left_fork);
        printf("Filósofo %d tomó el cubierto izquierdo.\n", philo->id + 1);
        
        pthread_mutex_lock(philo->right_fork);
        printf("Filósofo %d tomó el cubierto derecho y está comiendo.\n", philo->id + 1);

        // Comer
        usleep(philo->data->time_to_eat * 1000);
        philo->meals_eaten++;
        printf("Filósofo %d ha terminado de comer.\n", philo->id + 1);

        // Soltar cubiertos (desbloquear mutexes)
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);

        // Dormir
        printf("Filósofo %d está durmiendo...\n", philo->id + 1);
        usleep(philo->data->time_to_sleep * 1000);
    }
    
    return NULL;
}

void init_philosophers(t_data *data, t_philo *philos) {
    for (int i = 0; i < data->num_philo; i++) {
        philos[i].id = i;
        philos[i].meals_eaten = 0;
        philos[i].data = data;
        philos[i].left_fork = &data->forks[i];
        philos[i].right_fork = &data->forks[(i + 1) % data->num_philo];

        pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]);
    }
}

int main(int argc, char **argv) {
    if (argc < 5 || argc > 6) {
        printf("Uso: %s num_philosophers time_to_die time_to_eat time_to_sleep [num_meals]\n", argv[0]);
        return 1;
    }

    t_data data;
    data.num_philo = atoi(argv[1]);
    data.time_to_die = atoi(argv[2]);
    data.time_to_eat = atoi(argv[3]);
    data.time_to_sleep = atoi(argv[4]);
    data.num_philo_must_eat = (argc == 6) ? atoi(argv[5]) : -1;

    // Inicializar mutexes (cubiertos)
    data.forks = malloc(sizeof(pthread_mutex_t) * data.num_philo);
    for (int i = 0; i < data.num_philo; i++) {
        pthread_mutex_init(&data.forks[i], NULL);
    }

    // Crear filósofos
    t_philo *philos = malloc(sizeof(t_philo) * data.num_philo);
    init_philosophers(&data, philos);

    // Esperar a que los hilos terminen (opcional por ahora)
    for (int i = 0; i < data.num_philo; i++) {
        pthread_join(philos[i].thread, NULL);
    }

    // Liberar memoria y destruir mutexes
    for (int i = 0; i < data.num_philo; i++) {
        pthread_mutex_destroy(&data.forks[i]);
    }
    free(data.forks);
    free(philos);

    return 0;
}


