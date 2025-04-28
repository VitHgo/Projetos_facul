#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "log.h"

char* gera_campo(int diff){

    char *campo;

    if(diff == 1){

        campo = malloc(sizeof(char) * 10*10);
        for(int cont = 0; cont < 10*10; cont++){
            campo[cont] = 'x';
        }

    }
    else if(diff == 2){

        campo = malloc(sizeof(char) * 20*20);
        for(int cont = 0; cont < 20*20; cont++){
            campo[cont] = 'x';
        }

    }
    else if(diff == 3){

        campo = malloc(sizeof(char) * 30*30);
        for(int cont = 0; cont < 30*30; cont++){
            campo[cont] = 'x';
        }

    }

    return campo;

}

void coloca_bombas(char *campogbt, int diff){

    srand(time(NULL));

    int numBomb, contBomb = 0, coordx, coordy, tamanho;

    if(diff == 1){
        numBomb = 15;
        tamanho = 10;
    }
    else if(diff == 2){
        numBomb = 60;
        tamanho = 20;
    }
    else if(diff == 3){
        numBomb = 135;
        tamanho = 30;
    }

    while(contBomb < numBomb){

        coordx = rand()%tamanho;
        coordy = rand()%tamanho;
        if(coordx == tamanho) coordx -= 1;
        if(coordy == tamanho) coordy -= 1;
        if(campogbt[coordx*tamanho+coordy] == 'x'){
            campogbt[coordx*tamanho+coordy] = '*';
            contBomb++;
        }

    }
    
}

void imprime_campo(char *campo, int diff){

    int tam;

    if(diff == 1) tam = 10;
    else if(diff == 2) tam = 20;
    else if(diff == 3) tam = 30;

    for(int cont = 0; cont <= tam; cont++){
        printf("%d   ", cont);
    }

    printf("\n");

    for(int i = 0; i < tam; i++){
        printf("%d  ", i+1);
        for(int j = 0; j < tam; j++){
            if(i < 9){
                if(campo[i*tam+j] == 'x') printf(" x  ");
                else if(campo[i*tam+j] == '*') printf(" -1  ");
                else printf(" %c  ", campo[i*tam+j]);
            }
            else{
                if(campo[i*tam+j] == 'x') printf("x   ");
                else if(campo[i*tam+j] == '*') printf("-1   ");
                else printf("%c   ", campo[i*tam+j]);
            }
        }
        printf("\n");
    }
}

void minas_adjacentes(char *campogbt, char *campojgd, int tam, int x, int y){

    int contbomb = 0;

    if (x - 1 >= 0 && campogbt[(x-1)*tam+y] == '*') {
        contbomb++;
        //verifica emcima
    }

    if (x + 1 < tam && campogbt[(x+1)*tam+y] == '*') {
        contbomb++;
        //verifica embaixo
    }

    if (y - 1 >= 0 && campogbt[x*tam+(y-1)] == '*') {
        contbomb++;
        //verifica a esquerda
    }

    if (y + 1 < tam && campogbt[x*tam+(y+1)] == '*') {
        contbomb++;
        //verifica a direita
    }

    if (x - 1 >= 0 && y - 1 >= 0 && campogbt[(x-1)*tam+(y-1)] == '*') {
        contbomb++;
        //verifica o canto superior esquerdo
    }

    if (x - 1 >= 0 && y + 1 < tam && campogbt[(x-1)*tam+(y+1)] == '*') {
        contbomb++;
        //verifica o canto superior direito
    }

    if (x + 1 < tam && y - 1 >= 0 && campogbt[(x+1)*tam+(y-1)] == '*') {
        contbomb++;
        //verifica o canto inferior esquerdo
    }

    if (x + 1 < tam && y + 1 < tam && campogbt[(x+1)*tam+(y+1)] == '*') {
        contbomb++;
        //verifica o canto inferior direito
    }

    if(contbomb == 0) campojgd[x*tam+y] = '0';
    if(contbomb == 1) campojgd[x*tam+y] = '1';
    if(contbomb == 2) campojgd[x*tam+y] = '2';
    if(contbomb == 3) campojgd[x*tam+y] = '3';
    if(contbomb == 4) campojgd[x*tam+y] = '4';
    if(contbomb == 5) campojgd[x*tam+y] = '5';
    if(contbomb == 6) campojgd[x*tam+y] = '6';
    if(contbomb == 7) campojgd[x*tam+y] = '7';
    if(contbomb == 8) campojgd[x*tam+y] = '8';

}

void insere_valores_vizinhos(char *campogbt, int tam, int x, int y){

    int contbomb = 0;

    if(campogbt[x*tam+y] == '*') return;

    if (x - 1 >= 0 && campogbt[(x-1)*tam+y] == '*') {
        contbomb++;
        //verifica emcima
    }

    if (x + 1 < tam && campogbt[(x+1)*tam+y] == '*') {
        contbomb++;
        //verifica embaixo
    }

    if (y - 1 >= 0 && campogbt[x*tam+(y-1)] == '*') {
        contbomb++;
        //verifica a esquerda
    }

    if (y + 1 < tam && campogbt[x*tam+(y+1)] == '*') {
        contbomb++;
        //verifica a direita
    }

    if (x - 1 >= 0 && y - 1 >= 0 && campogbt[(x-1)*tam+(y-1)] == '*') {
        contbomb++;
        //verifica o canto superior esquerdo
    }

    if (x - 1 >= 0 && y + 1 < tam && campogbt[(x-1)*tam+(y+1)] == '*') {
        contbomb++;
        //verifica o canto superior direito
    }

    if (x + 1 < tam && y - 1 >= 0 && campogbt[(x+1)*tam+(y-1)] == '*') {
        contbomb++;
        //verifica o canto inferior esquerdo
    }

    if (x + 1 < tam && y + 1 < tam && campogbt[(x+1)*tam+(y+1)] == '*') {
        contbomb++;
        //verifica o canto inferior direito
    }

    if(contbomb == 0) campogbt[x*tam+y] = '0';
    if(contbomb == 1) campogbt[x*tam+y] = '1';
    if(contbomb == 2) campogbt[x*tam+y] = '2';
    if(contbomb == 3) campogbt[x*tam+y] = '3';
    if(contbomb == 4) campogbt[x*tam+y] = '4';
    if(contbomb == 5) campogbt[x*tam+y] = '5';
    if(contbomb == 6) campogbt[x*tam+y] = '6';
    if(contbomb == 7) campogbt[x*tam+y] = '7';
    if(contbomb == 8) campogbt[x*tam+y] = '8';

}

int dentro_limites(int linha, int coluna, int tam){
    return linha >= 0 && linha < tam && coluna >= 0 && coluna < tam;
}

void flood_fill(char *campojgd, char *campogbt, int linha, int coluna, int tam, int *contvit){

    if(!dentro_limites(linha, coluna, tam)) return;
    if(campojgd[linha*tam+coluna] == '0') return;
    if(campojgd[linha*tam+coluna] == '1') return;
    if(campojgd[linha*tam+coluna] == '2') return;
    if(campojgd[linha*tam+coluna] == '3') return;
    if(campojgd[linha*tam+coluna] == '4') return;
    if(campojgd[linha*tam+coluna] == '5') return;
    if(campojgd[linha*tam+coluna] == '6') return;
    if(campojgd[linha*tam+coluna] == '7') return;
    if(campojgd[linha*tam+coluna] == '8') return;
    //if(campogbt[linha*tam+coluna] == '*') return;

    minas_adjacentes(campogbt, campojgd, tam, linha, coluna);
    (*contvit)++;

    if(campojgd[linha*tam+coluna] != '0') return;

    flood_fill(campojgd, campogbt, linha-1, coluna, tam, contvit); //cima
    flood_fill(campojgd, campogbt, linha+1, coluna, tam, contvit); //baixo
    flood_fill(campojgd, campogbt, linha, coluna-1, tam, contvit); //esquerda
    flood_fill(campojgd, campogbt, linha, coluna+1, tam, contvit); //direita
    flood_fill(campojgd, campogbt, linha-1, coluna-1, tam, contvit); //diagonal superior esquerda
    flood_fill(campojgd, campogbt, linha-1, coluna+1, tam, contvit); //diagonal superior direita
    flood_fill(campojgd, campogbt, linha+1, coluna-1, tam, contvit); //diagonal inferior esquerda
    flood_fill(campojgd, campogbt, linha+1, coluna+1, tam, contvit); //diagonal inferior direita

    return;

}

int seleciona_coord(char *cmpjgd, char *cmpgbt, int tam, int x, int y, int *contvit){

    x = x-1;
    y = y-1;

    if(cmpgbt[x*tam+y] == '*'){
        return 1;
    }
    else{
        flood_fill(cmpjgd, cmpgbt, x, y, tam, contvit);
        return 0;
    }
}