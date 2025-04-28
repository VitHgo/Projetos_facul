#include <stdio.h>
#include <time.h>
#include "log.h"

void inicia_log(FILE *log){

    time_t tempo;
    tempo = time(NULL);
    log = fopen("log.txt", "a");

    fprintf(log, "\nLOG CAMPO MINADO");
    fprintf(log, "\n");
    fprintf(log, "DATA E HORA DE INICIO DO JOGO: %s", ctime(&tempo));

    fclose(log);

}

void registroGabarito(FILE *log, char *campogbt, int tam){

    log = fopen("log.txt", "a");

    fprintf(log, "\nCAMPO GABARITO");
    fprintf(log, "\n");

    for(int cont = 0; cont <= tam; cont++){
        fprintf(log, "%d   ", cont);
    }

    fprintf(log, "\n");

    for(int i = 0; i < tam; i++){
        fprintf(log, "%d  ", i+1);
        for(int j = 0; j < tam; j++){
            if(i < 9){
                fprintf(log, " %c  ", campogbt[i*tam+j]);
            }
            else{
                fprintf(log, "%c   ", campogbt[i*tam+j]);
            }
        }
        fprintf(log, "\n");
    }

    fprintf(log, "\nJOGADAS\n");

    fclose(log);

}

void registraJogada(FILE *log, char *campojgd, int linha, int coluna, int tam){

    log = fopen("log.txt", "a");

    fprintf(log, "\n");

    for(int cont = 0; cont <= tam; cont++){
        fprintf(log, "%d   ", cont);
    }

    fprintf(log, "\n");

    for(int i = 0; i < tam; i++){
        fprintf(log, "%d  ", i+1);
        for(int j = 0; j < tam; j++){
            if(i < 9){
                fprintf(log, " %c  ", campojgd[i*tam+j]);
            }
            else{
                fprintf(log, "%c   ", campojgd[i*tam+j]);
            }
        }
        fprintf(log, "\n");
    }

    fprintf(log, "\ncoordenadas inseridas: %d %d\n", linha, coluna);

    fclose(log);

}

void resultadoLog(FILE *log, int bomba){

    log = fopen("log.txt", "a");

    if(bomba == 0){
        fprintf(log, "\nparabens, voce eh fera\n");
    }
    else{
        fprintf(log, "\ngame over\n");
    }

    fclose(log);

}