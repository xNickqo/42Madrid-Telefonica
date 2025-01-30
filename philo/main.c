/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:29:40 by niclopez          #+#    #+#             */
/*   Updated: 2025/01/30 10:53:25 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Tu(s) programa(s) debe(n) aceptar los siguientes argumentos:
  number_of_philosophers time_to_die time_to_eat time_to_sleep
  [number_of_times_each_philosopher_must_eat]
  
    ◦ number_of_philosophers: es el número de filósofos, pero también el número
    de tenedores.

    ◦ time_to_die (en milisegundos): si un filósofo no empieza a comer en 
    time_to_die milisegundos desde el comienzo de su ultima comida o desde el 
    principio de la simulación, este morirá.

    ◦ time_to_eat (en milisegundos): es el tiempo que tiene un filósofo para 
    comer. Durante ese tiempo, tendrá los tenedores ocupados.

    ◦ time_to_sleep (en milisegundos): es el tiempo que tiene un filósofo para
    dormir.

    ◦ number_of_times_each_philosopher_must_eat (argumento opcional): si todos 
    los filósofos comen al menos number_of_times_each_philosopher_must_eat
    veces, la simulación se detendrá. Si no se especifica, la simulación se 
    detendrá con la muerte de un filósofo.

• Cada filósofo tendrá asignado un número del 1 al number_of_philosophers.

• El filósofo número 1 se sentará al lado del filósofo número 
  number_of_philosophers. Cualquier otro filósofo número N se sentarán entre 
  el filósofo número N - 1 y el filósofo número N + 1.

Los logs de tu programa:
• Cualquier cambio de estado de un filósofo debe tener el siguiente formato:
    ◦ timestamp_in_ms X has taken a fork
    ◦ timestamp_in_ms X is eating
    ◦ timestamp_in_ms X is sleeping
    ◦ timestamp_in_ms X is thinking
    ◦ timestamp_in_ms X died
Reemplaza timestamp_in_ms con la marca de tiempo actual en milisegundos
y X con el numero del filósofo.

• El estado impreso no debe estar roto o alterado por el estado de otros filósofos

• No puedes tener más de 10ms entre la muerte de un filósofo y el momento en el que
imprimes su muerte.

• Te recuerdo, los filósofos deben evitar morir

• Cada filósofo debe ser un hilo.

• Hay un tenedor entre cada filósofo. por lo tanto, si hay varios filósofos, cada filósofo
  debe tener un tenedor a su izquierda y otro a su derecha. si solo hay un filósofo,
  solo habrá un tenedor en la mesa.
  
• Para prevenir que los filósofos dupliquen los tenedores, deberás proteger los estados
  de los tenedores con un mutex por cada uno de ellos.
*/


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

/*
   5 [] 4
  []	[]
 1 [] [] 3
	  2
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define NUM_PHILOS 5

pthread_mutex_t tenedores[NUM_PHILOS];

void tomar_tenedores(int id) {
    // Para evitar deadlock, los filósofos pares toman primero el derecho
    if (id % 2 == 0) {
        pthread_mutex_lock(&tenedores[(id + 1) % NUM_PHILOS]); // Tenedor derecho
        pthread_mutex_lock(&tenedores[id]); // Tenedor izquierdo
    } else {
        pthread_mutex_lock(&tenedores[id]); // Tenedor izquierdo
        pthread_mutex_lock(&tenedores[(id + 1) % NUM_PHILOS]); // Tenedor derecho
    }
}

void soltar_tenedores(int id) {
    pthread_mutex_unlock(&tenedores[id]); // Soltar tenedor izquierdo
    pthread_mutex_unlock(&tenedores[(id + 1) % NUM_PHILOS]); // Soltar tenedor derecho
}

void *filosofo(void *arg) {
    int id = *(int *)arg;

    while (1) {
        printf("Filósofo %d está pensando...\n", id);
        usleep(1000000); // Simula el pensamiento

        printf("Filósofo %d intenta tomar los tenedores...\n", id);
        tomar_tenedores(id);

        printf("Filósofo %d está comiendo...\n", id);
        usleep(1000000); // Simula la comida

        printf("Filósofo %d terminó de comer y suelta los tenedores...\n", id);
        soltar_tenedores(id);
    }
}

int	main(int argc, char **argv)
{
	pthread_t philos[NUM_PHILOS];
	int id[NUM_PHILOS];
	int i;

	i = 0;
	while(i < NUM_PHILOS)
	{
		pthread_mutex_init(&tenedores[i], NULL);
		id[i] = i;
		i++;
	}

	while(i > NUM_PHILOS)
	{
		pthread_create(&philos[i], NULL, filosofo, &id[i]);
		pthread_join(philos[i], NULL);
		pthread_mutex_destroy(&tenedores[i]);
		i++;
	}

	return (0);
}