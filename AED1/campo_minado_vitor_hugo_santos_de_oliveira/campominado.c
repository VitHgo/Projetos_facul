#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "log.h"


int main(){

    char *campojgd, *campogbt; //ponteiros dos campo para o jogador e gabarito, respectivamente
    int dificuldade, tam, vitoria, condvitoria = 0, bomba = 0; //variaveis de parametro
    int *contvit;
    contvit = &condvitoria;
    FILE *log; //declaracao do ponteiro para o log campo minado

    if(log == NULL) printf("ERRO NO ARQUIVO\n");

    printf("Escolha a dificuldade:\n");//seleção da dificuldade do jogo
    printf("1-facil\n");
    printf("2-medio\n");
    printf("3-dificil\n");

    scanf("%d", &dificuldade);
    
    if(dificuldade == 1){ //selecao da dificuldade em 1-facil, 2-medio, 3-dificil
        tam = 10;
        vitoria = 85;
    }
    else if(dificuldade == 2){
        tam = 20;
        vitoria = 340;
    }
    else if(dificuldade == 3){
        tam = 30;
        vitoria = 765;
    }
    else{
        printf("dificuldade invalida\n");
        exit(1);
    }
    
    campojgd = gera_campo(dificuldade);  //inicialização do campo jogador
    campogbt = gera_campo(dificuldade); //inicialização do campo gabarito

    coloca_bombas(campogbt, dificuldade); //insere as bombas aleatoriamente pelo campo gabarito
    for(int x = 0; x < tam; x++){
        for(int y = 0; y < tam; y++){
            insere_valores_vizinhos(campogbt, tam, x, y); //insere os valores no gabarito que apontam a bomba mais proxima
        }
    }

    imprime_campo(campojgd, dificuldade); //imprime o campo para o jogador
    inicia_log(log); //inicializa o log e o prepara para inserir as informações
    registroGabarito(log, campogbt, tam); //registra o gabarito no log

    int coordx, coordy;
    printf("O jogo esta pronto para comecar!\n"); // inicio do jogo
    printf("Informe a linha e coluna, respectivamente, que deseja verificar:\n");
    scanf("%d,%d", &coordx, &coordy);


    //abaixo ocorre a logica do jogo para receber as coordenadas e verificando a condição de vitoria ou derrota
    //contvit é o contador de espaços que devem ser revelados para ganhar, e vitoria o parametro de parada
    //caso uma bomba seja selecionada, bomba é o parametro de parada para a derrota


    while(*contvit < vitoria && bomba == 0){
        if(seleciona_coord(campojgd, campogbt, tam, coordx, coordy, contvit) == 0){
            imprime_campo(campojgd, dificuldade);
            registraJogada(log, campojgd, coordx, coordy, tam);
        }
        else{
            imprime_campo(campogbt, dificuldade);
            printf("\n");
            registraJogada(log, campojgd, coordx, coordy, tam);
            bomba = 1; //final perdedor
            break;
        }

        printf("Informe novas coordenadas:\n");
        scanf("%d,%d", &coordx, &coordy);
    }

    if(bomba == 0){ 
        printf("parabens, vc eh fera"); //final vitorioso e registro no log
        resultadoLog(log, bomba);
    }
    else{
        printf("game over"); //final perdedor e registro no log
        resultadoLog(log, bomba);
    }

    free(campogbt); //liberação da memoria dos campos
    free(campojgd);

    return 0;
}