/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:29:40 by niclopez          #+#    #+#             */
/*   Updated: 2025/02/28 00:56:23 by niclopez         ###   ########.fr       */
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
pthread_mutex_t print_mutex;

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

void print_status(int id, char *status)
{
    unsigned long	timestamp;

	pthread_mutex_lock(&print_mutex);
	timestamp = get_time() - (start_time.tv_sec * 1000);
    printf("%lums Philosopher [%d] %s\n", timestamp, id + 1, status);
	pthread_mutex_unlock(&print_mutex);
}

void *philosopher_routine(void *arg)
{
    t_philo	*p;

	p = (t_philo *)arg;
    while (p->meals_eaten < p->data->num_philo_must_eat || p->data->num_philo_must_eat == -1) {
		print_status(p->id, "is thinking");
        usleep(5000);

		// Tomar cubiertos (bloquear mutexes)
        pthread_mutex_lock(p->left_fork);
        print_status(p->id, "took left fork");
        pthread_mutex_lock(p->right_fork);
        print_status(p->id, "took right fork and is eating");

		// Comer
        usleep(p->data->time_to_eat * 1000);
        p->meals_eaten++;
        print_status(p->id, "finished eating");

		// Soltar cubiertos (desbloquear mutexes)
        pthread_mutex_unlock(p->left_fork);
        pthread_mutex_unlock(p->right_fork);

		// Dormir
        print_status(p->id, "is sleeping");
        usleep(p->data->time_to_sleep * 1000);
    }
    return (NULL);
}

int main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;
	int		i;

    if (argc < 5 || argc > 6)
	{
        printf("Uso: %s num_philosophers time_to_die time_to_eat time_to_sleep [num_meals]\n", argv[0]);
        return (1);
    }

	if (!check_params(&data, argc, argv))
		return (1);

	gettimeofday(&start_time, NULL);
	pthread_mutex_init(&print_mutex, NULL);

    // Inicializar mutexes (cubiertos)
    data.forks = malloc(sizeof(pthread_mutex_t) * data.num_philo);
	i = 0;
    while(i < data.num_philo)
	{
        pthread_mutex_init(&data.forks[i], NULL);
		i++;
    }

    // Crear filósofos
    philos = malloc(sizeof(t_philo) * data.num_philo);
	i = 0;
    while (i < data.num_philo)
	{
        philos[i].id = i;
        philos[i].meals_eaten = 0;
        philos[i].data = &data;
        philos[i].left_fork = &data.forks[i];
        philos[i].right_fork = &data.forks[(i + 1) % data.num_philo];
        pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]);
		i++;
    }

    // Esperar a que los hilos terminen (opcional por ahora)
	i = 0;
    while (i < data.num_philo)
	{
        pthread_join(philos[i].thread, NULL);
		i++;
    }

    // Liberar memoria y destruir mutexes
	i = 0;
    while (i < data.num_philo)
	{
        pthread_mutex_destroy(&data.forks[i]);
		i++;
    }

	pthread_mutex_destroy(&print_mutex);
    free(data.forks);
    free(philos);

    return (0);
}
