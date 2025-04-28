#ifndef LOG_H
#define LOG_H


//esta função abre ou cria o arquivo log.txt, inserindo o cabeçalho com o dia e mes, em ingles, e o horario em que começou
//o jogo, recebendo da main o ponteiro do file
void inicia_log(FILE *log);


//esta função irá inserir no log.txt o campo gabarito, recebendo o ponteiro file, o ponteiro do campo gabarito e
//o tamanho do campo para a impressão no log
void registroGabarito(FILE *log, char *campogbt, int tam);


//esta função irá registrar o campo do jogador e as coordenas que ele inseriu para tal após cada jogada realizada,
//recebendo o ponteiro file, o ponteiro do campo jogador, a linha e coluna inserida, e o tamanho do campo para impressão
void registraJogada(FILE *log, char *campojgd, int linha, int coluna, int tam);


//esta função irá registrar no log.txt o resultado do jogo, se voce eh fera, ou game over, recebendo o ponteiro file
//e o parametro bomba da main
void resultadoLog(FILE *log, int bomba);

#endif