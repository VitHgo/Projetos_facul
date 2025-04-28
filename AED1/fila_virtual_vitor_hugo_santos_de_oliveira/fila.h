#ifndef FILA_H
#define FILA_H

typedef struct lista Lista; //definição do nome Lista para a struct que inicia a lista com prim e fim
typedef struct listano ListaNo; //definição do nome ListaNo para a struct dos nós(elementos) da lista

struct lista{ //struct da lista
    ListaNo* prim;
    ListaNo* fim;
};

struct listano{ // struct dos nós da lista
    int idade;
    ListaNo* ant;
    ListaNo* prox;
};

//função que cria a lista, alocando memória para os ponteiros que marcam o inicio e fim da lista
//ela retorna o ponteiro da lista, para inserção, alteração ou retirada de elementos
Lista* lst_cria();

//função que insere os elementos no fim da lista, recebendo como parâmetros o ponteiro da lista, e o valor
//(neste caso, a idade) que será inserido no nó(elemento). Sempre que adicionar um elemento, ele será inserido 
//no final(lado direito) da lista, como em uma fila
void lst_insere_fim(Lista* l, int idade);

//função que imprime todos os elementos da lista, neste caso, as idades inseridas em cada nó. Ela irá sempre começar do inicio
//(esquerda) para o fim(direita) da fila, e recebe como parâmetro o ponteiro da lista.
void lst_imprime(Lista* l);

//função que retira os elementos da lista, informando qual o valor que está contido no nó que será excluído, e por fim
//liberando a memória alocada. Ela sempre eliminará o elemento mais a esquerda(inicio da fila). Recebe o ponteiro da lista
//como parâmetro
void lst_retira(Lista* l);

//função que irá organizar na ordem decrescente(do maior para o menor) a lista, por meio do método bubble sort. Recebe como
//parâmetro o ponteiro da lista 
void bubble_sort(Lista* l);

//função que libera a memória alocada para a lista, bem como a memória alocada para os elementos também, caso reste 
//algo na lista após a execução do programa(medida de segurança)
void lst_libera(Lista* l);

#endif