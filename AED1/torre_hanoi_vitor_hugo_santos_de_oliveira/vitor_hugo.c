#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//Esta função verifica se o movimento desejado pelo jogador é válido, ou seja, se quando o movimento for realizado,
//o disco que ficará no topo da pilha será maior que o disco abaixo dele
int verifica_move(Pilha *p1, Pilha *p2);

int main(){

    int Cd1, Cd2, Jogadas = 0, vitoria = 0, NumDiscos;

    printf("Jogo Torre de Hanoi\n");
    printf("Insira o numero de pinos para comecar\n");

    Pilha *pilha1;
    Pilha *pilha2;
    Pilha *pilha3;

    while(scanf("%d", &NumDiscos)){  //seleção da quantidade de discos
        if(NumDiscos >= 2){

            int contPino = NumDiscos;

            pilha1 = cria_pilha();
            pilha2 = cria_pilha(); //criação dos pinos
            pilha3 = cria_pilha();
            
            for(int cont = 0; contPino > cont; contPino--){
                insere_pilha(pilha1, contPino); //inserção dos pinos iniciais no primeiro pino
            }

            printf("\n");

            imprime_pilhas(pilha1,pilha2,pilha3, NumDiscos); //impressão da interface do jogador
            printf("- - -\n"); //impressão da interface do jogador
            printf("1 2 3\n"); //impressão da interface do jogador
            break;
        }
        else{
            printf("Numero invalido, insira um valor maior ou igual a 2!\n"); //para jogar, é necessario inserir, no minimo
        }                                                                     //2 pinos, senão, será inválido
    }

    printf("\n");

    printf("Insira a jogada:\n"); //inicio do jogo
    while(vitoria != 1){

        scanf("%d,%d", &Cd1, &Cd2); //leitura do movimento do jogador

        printf("\njogada: %d,%d\n", Cd1, Cd2);

        //casos de movimento, sendo 6 possibilidades possiveis com 3 pinos distintos, assim,
        //ele verifica o caso e se é um movimento válido, onde o disco superior será sempre menor que o inferior

        if(Cd1 == 1 && Cd2 == 2 && verifica_move(pilha1, pilha2)){
            insere_pilha(pilha2, retira_pilha(pilha1));
        }
        else if(Cd1 == 1 && Cd2 == 3 && verifica_move(pilha1, pilha3)){
            insere_pilha(pilha3, retira_pilha(pilha1));
        }
        else if(Cd1 == 2 && Cd2 == 1 && verifica_move(pilha2, pilha1)){
            insere_pilha(pilha1, retira_pilha(pilha2));
        }
        else if(Cd1 == 2 && Cd2 == 3 && verifica_move(pilha2, pilha3)){
            insere_pilha(pilha3, retira_pilha(pilha2));
        }
        else if(Cd1 == 3 && Cd2 == 1 && verifica_move(pilha3, pilha1)){
            insere_pilha(pilha1, retira_pilha(pilha3));
        }
        else if(Cd1 == 3 && Cd2 == 2 && verifica_move(pilha3, pilha2)){
            insere_pilha(pilha2, retira_pilha(pilha3));
        }
        else{
            printf("\nJogada invalida\n");
            Jogadas--;
        }

        Jogadas++; //conta a quantidade de jogadas
        
        printf("\n");
        imprime_pilhas(pilha1,pilha2,pilha3, NumDiscos); //impressão da interface do jogador
        printf("- - -\n"); //impressão da interface do jogador
        printf("1 2 3\n"); //impressão da interface do jogador
        

        if(pilha2->tamanho == NumDiscos || pilha3->tamanho == NumDiscos){ //critério de vitória
            printf("\nVOCE GANHOU!!\n");
            printf("\nNumero de jogadas: %d\n", Jogadas);
            vitoria = 1;
        }
        else{
            printf("\nInsira a jogada:\n"); //continua o jogo
        }

    }

    libera_pilha(pilha1);
    libera_pilha(pilha2); //libera a mémoria das pilhas
    libera_pilha(pilha3);

    return 0;

}

int verifica_move(Pilha *p1, Pilha *p2){

    if(p2->prim == NULL) return 1;

    if(p1->prim->valor > p2->prim->valor) return 0;
    else return 1;

}