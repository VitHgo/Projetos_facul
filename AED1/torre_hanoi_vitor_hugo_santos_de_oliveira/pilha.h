#ifndef FILA_H
#define FILA_H

typedef struct pilha Pilha;
typedef struct pilhano PilhaNo;

struct pilha{ //struct da lista, tendo o ponteiro do primeiro elemento e o tamanho da lista.
    PilhaNo* prim;
    int tamanho;
};

struct pilhano{ //struct dos elementos da lista, tendo o ponteiro do próximo elemento e o valor do próprio elemento.
    int valor;
    PilhaNo* prox;
};

//função que cria a pillha, inicializando as váriaveis e ponteiros da pilha, recebendo void e retornando o
//ponteiro da pilha.
Pilha *cria_pilha();

//função que insere elementos na pilha, no caso do jogo, os discos. Recebe o ponteiro da pilha que será incrementada e
//o valor do elemento que será criado e inserido.
void insere_pilha(Pilha *pilha, int v);

//função que imprime as três pilhas, no caso do jogo, os pinos. Ela recebe os ponteiros de cada pino, respectivamente,
//e imprime todos os elementos no formato da interface para o jogador, sendo na vertical e cada pilha um do lado da outra.
//Também recebe o número de discos determinado no jogo, para a impressão correta.
void imprime_pilhas(Pilha *pilha1, Pilha *pilha2, Pilha *pilha3, int numDiscos);

//função que retira um elemento da pilha. Ela recebe o ponteiro da pilha(pino) que será retirada o elemento(disco) e
//retorna o valor do disco que foi retirado, para ser usado depois para ser inserido no pino desejado
int retira_pilha(Pilha* pilha);

//função que libera a mémoria da pilha(pino) desejado, recebendo o ponteiro da determinada pilha e liberando também
//os elementos nela, e assim que todos os elementos são liberados, libera também a mémoria alocada da pilha
void libera_pilha(Pilha *pilha);

#endif
