#include <stdio.h>
#include <pthread.h>
#define N_THREADS 2
#define N_ITERS 1000000

int contador = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;;

void* tarefa(void* arg) {
    for (int i = 0; i < N_ITERS; i++) {
        pthread_mutex_lock(&lock);
        contador++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[N_THREADS];
    for (int i = 0; i < N_THREADS; i++)
        pthread_create(&threads[i], NULL, tarefa, NULL);
    for (int i = 0; i < N_THREADS; i++)
        pthread_join(threads[i], NULL);
    printf("Contador final: %d (esperado: %d)\n", contador, N_THREADS * N_ITERS);
    pthread_mutex_destroy(&lock);
    return 0;
}
