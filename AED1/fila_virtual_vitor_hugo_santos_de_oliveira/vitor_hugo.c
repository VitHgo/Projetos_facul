#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){

    Lista* l = lst_cria(); //criação da lista
    int idade, QuantP;

    FILE *lista; //ponteiro FILE para o arquivo com os clientes
    lista = fopen("clientes.txt", "r"); //abertura do arquivo com os clientes

    if(lista != NULL) printf("\nFila do Bradesco aberta com sucesso!\n"); //verificação se o arquvio foi aberto corretamente
    else printf("\nFila do Bradesco fechada, tente novamente mais tarde\n");

    while(fscanf(lista, "%d", &idade) != EOF){ //leitura das idades
        lst_insere_fim(l, idade);
    }
    fclose(lista); //fechamento do arquivo

    printf("Fila atual:\n");
    lst_imprime(l);
    printf("\nOrganizando por prioridade de idade...\n");
    bubble_sort(l); //organização da lista de forma decrescente com bubble sort
    lst_imprime(l);

    printf("\nComecando atendimento\n");
    while(l->prim != NULL){ //retirando todos os elementos da lista pelo inicio da fila
        lst_retira(l);
    }

    printf("\nFila encerrada, fechando sistema, volte amanha\n");

    lst_libera(l); //liberação da lista

    return 0;
}