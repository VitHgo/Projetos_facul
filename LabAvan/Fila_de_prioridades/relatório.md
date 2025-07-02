
# Enunciado: Fila de Prioridade com Repriorização Dinâmica

## Alunos

- Vitor Hugo Santos de Oliveira
- Sofia da Silva Souza

## Objetivo
Projetar e implementar uma fila de prioridade concorrente que permita não apenas a inserção e remoção de itens com prioridade, mas também a **repriorização de um item já presente na fila**, de forma segura e eficiente.

## Descrição
Você deve desenvolver uma estrutura de dados que suporte as seguintes operações concorrentes:

- `inserir(item, prioridade)`
- `remover()`
- `repriorizar(item, nova_prioridade)`

A operação de **repriorização** deve localizar o item na estrutura, atualizar seu valor de prioridade e reorganizar a estrutura conforme necessário.

## Tipo de Dado
Cada item representa um **pedido de leitura de sensor de temperatura** e contém:

- `id_dispositivo`
- `timestamp`
- `prioridade`

## Dinâmica de Atualização
Uma thread externa simula mudanças ambientais e chama `repriorizar` aleatoriamente.

## Instruções de Execução
1. Compile com `make`
2. Execute com `./repriorizacao`

## Relatório de Resultados
Documente os seguintes casos de teste:

### Caso 1: Alta concorrência de inserção
- **Variável:** N_PROD 5.
- **Importância:** as threads de inserção funcionaram normalmente. Porém, algumas entravam em um estado de espera e apenas eram chamadas
minutos depois.
- **Tempo de execução:** 0.140 segundos.
- **Modificação:** foi modificado o intervalo do rand para fazer com que o programa pudesse operar sem erros, e para que ele também gerasse elementos na mesma quantidade de criação das threads. 
- **Número de atualizações**: 50 inserções.

### Caso 2: Alta frequência de repriorização
- **Variável:** N_REPR 5.
- **Importância:** as threads novamente funcionaram como deviam. Suportaram todas as repriorizações sem erros.
- **Tempo de execução:** 0.125 segundos.
- **Modificação:** foi modificado o intervalo do rand novamente para fazer com que o programa pudesse operar sem erros, e para que ele também gerasse elementos na mesma quantidade de criação das threads. 
- **Número de atualizações**: 38 repriorizações e 12 ids não encontrados.

### Caso 3: Consumo intenso
- **Variável:** N_CONS 5.
- **Importância:** as threads novamente funcionaram como deviam. Todos os itens colocados foram removidos devido ao grande número de threads de consumidor.
- **Tempo de execução:** 0.141 segundos.
- **Modificação:** foi modificado o intervalo do rand mais uma vez para fazer com que o programa pudesse operar sem erros, e para que ele também gerasse elementos na mesma quantidade de criação das threads. 
- **Número de atualizações**: 50 remoções.

Inclua no relatório:
- Tempo de execução
- Número de atualizações
- Observações

## Critérios de Avaliação
- Corretude funcional (40%)
- Sincronização segura (20%)
- Implementação da repriorização (20%)
- Relatório (20%)
