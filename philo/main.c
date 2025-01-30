/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <niclopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:29:40 by niclopez          #+#    #+#             */
/*   Updated: 2025/01/30 16:53:23 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Tu(s) programa(s) debe(n) aceptar los siguientes argumentos:
  num_philo time_to_die time_to_eat time_to_sleep
  [number_of_times_each_philosopher_must_eat]
  
    ◦ num_philo: es el número de filósofos, pero también el número
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

• Cada filósofo tendrá asignado un número del 1 al num_philo.

• El filósofo número 1 se sentará al lado del filósofo número 
  num_philo. Cualquier otro filósofo número N se sentarán entre 
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

struct timeval start_time;

float get_time_since_start() {
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    // Calcular la diferencia entre el tiempo actual y el tiempo de inicio
    return (current_time.tv_sec - start_time.tv_sec) * 1000.0f + 
           (current_time.tv_usec - start_time.tv_usec) / 1000.0f; // Retornar en milisegundos
}

void print_status(int id, char *status) {
    float timestamp = get_time_since_start();
    printf("%.3fms Philosopher %d %s\n", timestamp, id + 1, status);
}

void *filosofo(void *arg) {
    // Desempaquetar los parámetros recibidos
    int *params = (int *)arg;
    int id = params[0];
    int num_philo = params[1];
    int time_to_die = params[2];
    int time_to_eat = params[3];
    int time_to_sleep = params[4];
    int num_philo_must_eat = params[5];

    pthread_mutex_t tenedores[num_philo];
    int last_meal_time[num_philo];
    int times_ate[num_philo];
    int simulation_over = 0;

    // Inicialización de tenedores, tiempos y conteo de comidas
    for (int i = 0; i < num_philo; i++) {
        pthread_mutex_init(&tenedores[i], NULL);
        times_ate[i] = 0;
        last_meal_time[i] = get_time_since_start();
    }

    // Ciclo de simulación de los filósofos
    while (!simulation_over) {
        // Pensando
        print_status(id, "is thinking");
        usleep(time_to_sleep * 1000); // Tiempo de pensar

        // Intentando tomar tenedores
        pthread_mutex_lock(&tenedores[id]);
        pthread_mutex_lock(&tenedores[(id + 1) % num_philo]);
        
        // Comiendo
        print_status(id, "has taken a fork");
        print_status(id, "is eating");
        last_meal_time[id] = get_time_since_start();
        usleep(time_to_eat * 1000); // Tiempo de comer
        times_ate[id]++;
        
        // Revisar si el filósofo murió
        if (get_time_since_start() - last_meal_time[id] > time_to_die) {
            print_status(id, "died");
            simulation_over = 1;
            break;
        }

        // Soltar tenedores
        pthread_mutex_unlock(&tenedores[id]);
        pthread_mutex_unlock(&tenedores[(id + 1) % num_philo]);
        
        // Durmiendo
        print_status(id, "is sleeping");
        usleep(time_to_sleep * 1000); // Tiempo de dormir

        // Verificar si todos los filósofos han comido la cantidad necesaria
        if (num_philo_must_eat > 0) {
            int all_ate_enough = 1;
            for (int i = 0; i < num_philo; i++) {
                if (times_ate[i] < num_philo_must_eat) {
                    all_ate_enough = 0;
                    break;
                }
            }
            if (all_ate_enough) {
                simulation_over = 1;
                break;
            }
        }
    }

    // Destrucción de mutex
    for (int i = 0; i < num_philo; i++) {
        pthread_mutex_destroy(&tenedores[i]);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 5 || argc > 6) {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
        return 1;
    }

    // Inicializar el tiempo de inicio del programa
    gettimeofday(&start_time, NULL);

    // Parsear los parámetros del programa
    int num_philo = atoi(argv[1]);
    int time_to_die = atoi(argv[2]);
    int time_to_eat = atoi(argv[3]);
    int time_to_sleep = atoi(argv[4]);
    int num_philo_must_eat = (argc == 6) ? atoi(argv[5]) : -1;

    // Hilos de los filósofos
    pthread_t philosophers[num_philo];
    int params[num_philo][6]; // Arreglo para pasar parámetros a cada hilo

    // Crear los parámetros que pasaremos a cada filósofo
    for (int i = 0; i < num_philo; i++) {
        params[i][0] = i;                      // ID del filósofo
        params[i][1] = num_philo;              // Número de filósofos
        params[i][2] = time_to_die;            // Tiempo para morir
        params[i][3] = time_to_eat;            // Tiempo para comer
        params[i][4] = time_to_sleep;          // Tiempo para dormir
        params[i][5] = num_philo_must_eat;    // Número de veces que cada filósofo debe comer
        pthread_create(&philosophers[i], NULL, filosofo, (void *)params[i]);
    }

    // Esperar que todos los hilos terminen
    for (int i = 0; i < num_philo; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}


