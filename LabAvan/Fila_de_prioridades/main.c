
#include "fila_prioridade.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>

#define N_PROD 5
#define N_CONS 5
#define N_REPR 1

int cont;
int parada = 10;

void* produtor(void* arg) {
  
  for(int x = 0; x < parada; x++){

    Pedido novo;
    novo.id_dispositivo = cont;
    novo.timestamp = cont;
    cont++;
    novo.prioridade = rand() % 11;

    inserir(novo);
  }

  Sleep(rand() % 100);
  
  return NULL;
}

void* consumidor(void* arg) {
  
  for(int x = 0; x < parada; x++){
        Pedido removido = remover();

        printf("Pedido numero: %d removido\n", removido.id_dispositivo);

    }
    Sleep(rand() % 100);

    return NULL;
}

void* atualizador(void* arg) {

    
    for(int x = 0; x < parada; x++){

        int novo_id = rand() % 11;
        int nova_prioridade = rand() % 100;
        repriorizar(novo_id, nova_prioridade);

    }

    Sleep(rand() % 100);
}

int main() {

    DWORDLONG inicio = GetTickCount();

    pthread_t prod[N_PROD], cons[N_CONS], repr[N_REPR];
    inicializar_fila();
    srand(time(NULL));

    for (int i = 0; i < N_PROD; i++)
        pthread_create(&prod[i], NULL, produtor, NULL);
    for (int i = 0; i < N_CONS; i++)
        pthread_create(&cons[i], NULL, consumidor, NULL);
    for (int i = 0; i < N_REPR; i++)
        pthread_create(&repr[i], NULL, atualizador, NULL);

    for (int i = 0; i < N_PROD; i++)
        pthread_join(prod[i], NULL);
    for (int i = 0; i < N_CONS; i++)
        pthread_join(cons[i], NULL);
    for (int i = 0; i < N_REPR; i++){
        pthread_join(repr[i], NULL);
    }

    DWORDLONG fim = GetTickCount();
    double tempo_execucao = (fim - inicio) / 1000.0;

    printf("\nTempo total de execucao: %.3f segundos\n", tempo_execucao);
    
    return 0;
}
