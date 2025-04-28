#ifndef CAMPO_MINADO_H
#define CAMPO_MINADO_H


//função irá alocar os campos dinamicamente de acordo com a dificuldade definida na main, recebendo apenas o nivel de
//dificuldade e retornando o endereço do campo alocado dinamicamente
char* gera_campo(int diff);


//função irá imprimir no terminal os campos, tanto jogador quanto gabarito, apenas recebendo o ponteiro do campo desejado e
//a dificuldade definida na main
void imprime_campo(char *campo, int diff);


//função irá inserir as bombas no campo gabarito, de forma aleatória, e de acordo com a quantidade de bombas da
//dificuldade definida, recebendo o ponteiro do gabarito e o numero de bombas
void coloca_bombas(char *campogbt, int numBomb);


//função irá verificar as casas ao redor das coordenadas x e y inseridas, substituindo no campo do jogador quantas bombas existem
//nas casas vizinhas. Recebe o ponteiro do campo gabarito para comparação com o campo jogador, o tamanho dos campos e as
//coordenadas inseridas
void minas_adjacentes(char *campogbt, char *campojgd, int tam, int x, int y);


//função irá inserir no campo gabarito a quantidade de bombas ao redor da coordenada x e y inserida, recebendo
//o ponteiro do gabarito, o tamanho do campo, e a linha e coluna inseridas
void insere_valores_vizinhos(char *campogbt, int tam, int x, int y);


//função recursiva para realizar a mecânica flood fill do campo minado, recebendo o campo jogador e gabarito,
//a linha e coluna inseridas como coordenas, o tamanho dos campos, e o ponteiro de parametro de vitoria,
//para atualização do critério
void flood_fill(char *campojgd, char *campogbt, int linha, int coluna, int tam, int *contvit);


//função intermediaria responsável por receber as coordenadas e verificar se há bomba, e em caso negativo,
//repassar para o flood fill
int seleciona_coord(char *cmpjgd, char *cmpgbt, int tam, int x, int y, int *contvit);

#endif