---
marp: true
theme: dark
paginate: true
---

# LABORATÓRIO PRÁTICO - CONTROLE DE CONCORRÊNCIA COM SPINLOCK E MUTEX
## Aluno: Vitor Hugo Santos de Oliveira
## Matrícula: 22401953

---

## Código Spinlock

```c

#include <stdio.h>
#include <pthread.h>
#define N_THREADS 16
#define N_ITERS 1000000

int contador = 0;
pthread_spinlock_t splock;

void* tarefa(void* arg) {
    for (int i = 0; i < N_ITERS; i++) {
        pthread_spin_lock(&splock);
        contador++;
        pthread_spin_unlock(&splock);
    }
    return NULL;
}

int main() {
    pthread_t threads[N_THREADS];
    pthread_spin_init(&splock, PTHREAD_PROCESS_PRIVATE);
    for (int i = 0; i < N_THREADS; i++)
        pthread_create(&threads[i], NULL, tarefa, NULL);
    for (int i = 0; i < N_THREADS; i++)
        pthread_join(threads[i], NULL);
    printf("Contador final: %d (esperado: %d)\n", contador, N_THREADS * N_ITERS);
    pthread_spin_destroy(&splock);
    return 0;
}

```

---

## Código Mutex

```c

#include <stdio.h>
#include <pthread.h>
#define N_THREADS 16
#define N_ITERS 1000000

int contador = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;;

void* tarefa(void* arg) {
    for (int i = 0; i < N_ITERS; i++) {
        pthread_mutex_lock(&lock);
        contador++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[N_THREADS];
    for (int i = 0; i < N_THREADS; i++)
        pthread_create(&threads[i], NULL, tarefa, NULL);
    for (int i = 0; i < N_THREADS; i++)
        pthread_join(threads[i], NULL);
    printf("Contador final: %d (esperado: %d)\n", contador, N_THREADS * N_ITERS);
    pthread_mutex_destroy(&lock);
    return 0;
}

```

---

## Tabela Comparativa

| N° Threads | Tempo(Spinlock) | Tempo(Mutex) | Contador correto? |
|------------|-----------------|--------------|-------------------|
|     2      |      232ms      |    181ms     | ✅Correto        |
|     4      |      929ms      |    214ms     | ✅Correto        |
|     8      |      1520ms     |    383ms     | ✅Correto        |
|     16     |      4696ms     |    665ms     | ✅Correto        |

---

## Respostas

- Quando usar spinlock?
    - Spinlock deve ser usado quando temos um pequeno escopo que precisamos proteger, a chamada região crítica, e quando o processo não consumir muito da CPU e for rápido. 
- Quando mutex é mais adequado?
    - Mutex são mais adequados quando aplicamos eles em regiões críticas maiores, onde os bloqueios serão mais recorrentes e longos. Geralmente, processos mais longos e que consomem mais da CPU terão um desempenho melhor com mutex.
- Melhor eficiência no experimento?
    - O mutex se mostrou melhor no experimento, com tempos menores e mais consistentes, além de um crescimento muito menor de tempo de processamento, quando comparado com o spinlock. Vale ressaltar no tempo muito próximo que a spinlock e o mutex apresentaram no primeiro caso, o que podemos concluir que, com uma entrada menor, o spinlock pode entregar um tempo menor de processamento.
- Resultado sem sincronização?
    - Quando o programa é executado sem a sincronização, tanto sem o mutex quanto o spinlock, o contador demonstra não alcançar o valor esperado, em todos os casos, o que prova a importância de proteger as regiões críticas de seu código com mecanismos de sincronização como mutex ou spinlock.

---