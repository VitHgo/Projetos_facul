#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define TAMANHO_PRIORIDADE 10
#define NUM_PROD 2
#define NUM_CONS 2

int fila_prioridade[TAMANHO_PRIORIDADE];
int tamanho_atual = 0;
pthread_mutex_t mutex_prioridade;

void inserir_prioridade(int item) {
    pthread_mutex_lock(&mutex_prioridade);

    if (tamanho_atual < TAMANHO_PRIORIDADE) {
        int i = tamanho_atual;
        while (i > 0 && fila_prioridade[i - 1] < item) {
            fila_prioridade[i] = fila_prioridade[i - 1];
            i--;
        }
        fila_prioridade[i] = item;
        tamanho_atual++;
        printf("Inserido com prioridade: %d\n", item);
    }

    pthread_mutex_unlock(&mutex_prioridade);
}

int remover_prioridade() {
    pthread_mutex_lock(&mutex_prioridade);

    int item = -1;
    if (tamanho_atual > 0) {
        item = fila_prioridade[0];
        for (int i = 1; i < tamanho_atual; i++) {
            fila_prioridade[i - 1] = fila_prioridade[i];
        }
        tamanho_atual--;
        printf("Removido com prioridade: %d\n", item);
    }

    pthread_mutex_unlock(&mutex_prioridade);
    return item;
}

void* produtor_prioridade(void* arg) {
    int item, i = 0;
    while (i++ < 10) {
        item = rand() % 100;
        inserir_prioridade(item);
        sleep(1);
    }
    return NULL;
}

void* consumidor_prioridade(void* arg) {
    int item, i = 0;
    while (i++ < 10) {
        item = remover_prioridade();
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t prod_p[NUM_PROD], cons_p[NUM_CONS];
    pthread_mutex_init(&mutex_prioridade, NULL);

    for (int i = 0; i < NUM_PROD; i++)
        pthread_create(&prod_p[i], NULL, produtor_prioridade, NULL);
    for (int i = 0; i < NUM_CONS; i++)
        pthread_create(&cons_p[i], NULL, consumidor_prioridade, NULL);

    for (int i = 0; i < NUM_PROD; i++)
        pthread_join(prod_p[i], NULL);
    for (int i = 0; i < NUM_CONS; i++)
        pthread_join(cons_p[i], NULL);

    pthread_mutex_destroy(&mutex_prioridade);
    return 0;
}
