// Heap de prioridade com proteção por mutex (versão didática)
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TAMANHO_HEAP 100
#define NUM_PROD 2
#define NUM_CONS 2

int heap[TAMANHO_HEAP];
int tamanho = 0;

pthread_mutex_t mutex_heap;

void subir(int i) {
    while (i > 0) {
        int pai = (i - 1) / 2;
        if (heap[i] <= heap[pai]) break;
        int temp = heap[i];
        heap[i] = heap[pai];
        heap[pai] = temp;
        i = pai;
    }
}

void descer(int i) {
    while (2 * i + 1 < tamanho) {
        int filho_esq = 2 * i + 1;
        int filho_dir = 2 * i + 2;
        int maior = filho_esq;
        if (filho_dir < tamanho && heap[filho_dir] > heap[filho_esq]) {
            maior = filho_dir;
        }
        if (heap[i] >= heap[maior]) break;
        int temp = heap[i];
        heap[i] = heap[maior];
        heap[maior] = temp;
        i = maior;
    }
}

void inserir(int valor) {
    pthread_mutex_lock(&mutex_heap);
    if (tamanho < TAMANHO_HEAP) {
        heap[tamanho] = valor;
        subir(tamanho);
        tamanho++;
        printf("Inserido: %d\n", valor);
    }
    pthread_mutex_unlock(&mutex_heap);
}

int remover() {
    pthread_mutex_lock(&mutex_heap);
    int valor = -1;
    if (tamanho > 0) {
        valor = heap[0];
        heap[0] = heap[--tamanho];
        descer(0);
        printf("Removido: %d\n", valor);
    }
    pthread_mutex_unlock(&mutex_heap);
    return valor;
}

void* produtor(void* arg) {
    for (int i = 0; i < 10; i++) {
        int valor = rand() % 100;
        inserir(valor);
        sleep(1);
    }
    return NULL;
}

void* consumidor(void* arg) {
    for (int i = 0; i < 10; i++) {
        remover();
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t produtores[NUM_PROD], consumidores[NUM_CONS];
    pthread_mutex_init(&mutex_heap, NULL);

    for (int i = 0; i < NUM_PROD; i++)
        pthread_create(&produtores[i], NULL, produtor, NULL);
    for (int i = 0; i < NUM_CONS; i++)
        pthread_create(&consumidores[i], NULL, consumidor, NULL);

    for (int i = 0; i < NUM_PROD; i++)
        pthread_join(produtores[i], NULL);
    for (int i = 0; i < NUM_CONS; i++)
        pthread_join(consumidores[i], NULL);

    pthread_mutex_destroy(&mutex_heap);
    return 0;
}
