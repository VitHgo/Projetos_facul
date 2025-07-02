
#include "fila_prioridade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

static Pedido fila[TAM_MAX];
static int tamanho = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void bubble_sort(Pedido vet[]){

    int ordenado = 1;

    while(ordenado){

        ordenado = 0;
        for(int cont = 0; cont < tamanho-1; cont++){
            if(vet[cont].prioridade < vet[cont+1].prioridade){
                Pedido aux = vet[cont];
                vet[cont] = vet[cont+1];
                vet[cont+1] = aux;
                ordenado = 1;
            }
        }
    }

}

void inicializar_fila() {
    tamanho = 0;
}

void inserir(Pedido p) {

    pthread_mutex_lock(&mutex);
    fila[tamanho] = p;
    printf("Pedido numero: %d adicionado\n", fila[tamanho].id_dispositivo);

    tamanho++;

    bubble_sort(fila);
    pthread_mutex_unlock(&mutex);

}

Pedido remover() {

    pthread_mutex_lock(&mutex);
    Pedido resultado = fila[0];
    fila[0].prioridade = -1;

    bubble_sort(fila);
    tamanho--;
    pthread_mutex_unlock(&mutex);

    return resultado;
}

void repriorizar(int id_dispositivo, int nova_prioridade) {

    pthread_mutex_lock(&mutex);
    Pedido item;

    for(int x = 0; x < tamanho; x++){
        if(fila[x].id_dispositivo == id_dispositivo){
            fila[x].prioridade = nova_prioridade;
            bubble_sort(fila);
            printf("fila: ");
            for(int x = 0; x < tamanho; x++){
                printf("(%d,%d),", fila[x].id_dispositivo, fila[x].prioridade);
            }
            printf("\n");
            break;
        }
        else if(x == tamanho-1){
            printf("Id nao encontrado\n");
        }

    }

    pthread_mutex_unlock(&mutex);
}
