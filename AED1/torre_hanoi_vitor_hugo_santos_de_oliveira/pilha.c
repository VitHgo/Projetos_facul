#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha *cria_pilha(){

    Pilha *novo = malloc(sizeof(Pilha));

    if(novo == NULL){
        printf("erro ao criar pilha\n");
        exit(1);
    }

    novo->prim = NULL;
    novo->tamanho = 0;

    return novo;

}

void insere_pilha(Pilha *pilha, int v){

    PilhaNo *novo = malloc(sizeof(PilhaNo));

    if(novo == NULL){
        printf("erro ao inserir na pilha\n");
        exit(1);
    }

    novo->valor = v;
    novo->prox = pilha->prim;
    pilha->prim = novo;
    pilha->tamanho++;

}

void imprime_pilhas(Pilha *pilha1, Pilha *pilha2, Pilha *pilha3, int numDiscos){

    PilhaNo *p1;
    PilhaNo *p2;
    PilhaNo *p3;

    int linha = numDiscos;

    p1 = pilha1->prim;
    p2 = pilha2->prim;
    p3 = pilha3->prim;

    while(p1 != NULL || p2 != NULL || p3 != NULL){

        if(p1 != NULL && linha <= pilha1->tamanho){
            printf("%d ", p1->valor);
            p1 = p1->prox;
        }
        else{
            printf("  ");
        }
        if(p2 != NULL && linha <= pilha2->tamanho){
            printf("%d ", p2->valor);
            p2 = p2->prox;
        }
        else{
            printf("  ");
        }
        if(p3 != NULL && linha <= pilha3->tamanho){
            printf("%d ", p3->valor);
            p3 = p3->prox;
        }
        else{
            printf("  ");
        }

        printf("\n");
        linha--;

    }


}

int retira_pilha(Pilha* pilha){

    if(pilha->prim == NULL){
        printf("pilha vazia\n");
        exit(1);
    }

    PilhaNo *t;
    t = pilha->prim;
    int v = t->valor;
    pilha->prim = t->prox;
    free(t);
    pilha->tamanho--;
    return v;

}

void libera_pilha(Pilha *pilha){

    PilhaNo *t;
    t = pilha->prim;

    while(t != NULL){
        PilhaNo *u;
        u = t->prox;
        free(t);
        t = u;
    }

    free(pilha);

}

