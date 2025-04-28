#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Lista* lst_cria(){

    Lista* l = malloc(sizeof(Lista));
    if(l == NULL){
        printf("Erro ao criar lista\n");
        exit(1);
    }

    l->prim = NULL;
    l->fim = NULL;
 
    return l;
}

void lst_insere_fim(Lista* l, int idade){

    ListaNo* novo = malloc(sizeof(ListaNo));
    if(novo == NULL){
        printf("Erro ao criar nó para lista\n");
        exit(1);
    }
    novo->idade = idade;
    novo->prox = l->prim;
    novo->ant = NULL;

    if(l->fim != NULL){
        l->fim->ant = novo;
    }
    else{
        l->prim = novo;
    }
    l->fim = novo;

}

void lst_imprime(Lista* l){

    ListaNo* p = l->prim;

    for(p; p != NULL; p = p->ant){
        printf("%d ", p->idade);
    }
    printf("\n");

}

void lst_retira(Lista* l){

    ListaNo* p = l->prim;

    printf("\nCliente de idade %d atendido\n", p->idade);

    l->prim = p->ant;

    free(p);
    printf("Resto da fila:\n");
    lst_imprime(l);

}

void bubble_sort(Lista* l){

    int stop = 0;

    while(stop == 0){

        stop = 1;

        for(ListaNo* p = l->prim; p->ant != NULL; p = p->ant){
            if(p->idade < p->ant->idade){
                if(p == l->prim){
                    l->prim = p->ant;
                    p->ant->prox = p->prox;
                    p->ant->ant->prox = p;
                    p->prox = p->ant;
                    p->ant = p->ant->ant;
                    p->prox->ant = p;
                }
                else if(p->ant == l->fim){
                    p->ant->prox = p->prox;
                    p->prox->ant = p->ant;
                    p->prox = p->ant;
                    p->ant = p->ant->ant;
                    p->prox->ant = p;
                    l->fim = p;
                }
                else{
                    p->ant->prox = p->prox;
                    p->prox->ant = p->ant;
                    p->ant->ant->prox = p;
                    p->prox = p->ant;
                    p->ant = p->prox->ant;
                    p->prox->ant = p;
                }

                p = p->prox;
                stop = 0;
            }

        }

    }

}

void lst_libera(Lista* l){

    ListaNo* p = l->prim;

    for(p; p != NULL; p->ant){
        lst_retira(l);
    }

    free(l);

}


