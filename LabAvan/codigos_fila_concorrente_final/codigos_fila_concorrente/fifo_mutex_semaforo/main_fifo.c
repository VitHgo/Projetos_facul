#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define TAMANHO 5
#define NUM_PROD 2
#define NUM_CONS 2

int buffer[TAMANHO];
int entrada = 0, saida = 0;

pthread_mutex_t mutex;
sem_t vazio, cheio;

void* produtor(void* arg) {
    int item, i = 0;
    while (i++ < 10) {
        item = rand() % 100;
        sem_wait(&vazio);
        pthread_mutex_lock(&mutex);

        buffer[entrada] = item;
        printf("Produzido: %d\n", item);
        entrada = (entrada + 1) % TAMANHO;

        pthread_mutex_unlock(&mutex);
        sem_post(&cheio);
    }
    return NULL;
}

void* consumidor(void* arg) {
    int item, i = 0;
    while (i++ < 10) {
        sem_wait(&cheio);
        pthread_mutex_lock(&mutex);

        item = buffer[saida];
        printf("Consumido: %d\n", item);
        saida = (saida + 1) % TAMANHO;

        pthread_mutex_unlock(&mutex);
        sem_post(&vazio);
    }
    return NULL;
}

int main() {
    pthread_t prod[NUM_PROD], cons[NUM_CONS];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&vazio, 0, TAMANHO);
    sem_init(&cheio, 0, 0);

    for (int i = 0; i < NUM_PROD; i++)
        pthread_create(&prod[i], NULL, produtor, NULL);
    for (int i = 0; i < NUM_CONS; i++)
        pthread_create(&cons[i], NULL, consumidor, NULL);

    for (int i = 0; i < NUM_PROD; i++)
        pthread_join(prod[i], NULL);
    for (int i = 0; i < NUM_CONS; i++)
        pthread_join(cons[i], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&vazio);
    sem_destroy(&cheio);
    return 0;
}
