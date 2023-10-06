

#include <stdbool.h>

#define MAX 7

typedef struct ponto ponto2D;

/*
Entrada: lista P
Saída: capacidade da lista
*/
int capacidade(ponto2D *P);

/*
Entrada: lista P
Saída: verdadeiro se estiver cheia; falso caso contrário
*/
bool cheia(ponto2D *P);

/*
Cria uma lista sequencial de pontos
Entrada: Não tem
Saída: endereço da memória alocada para a lista
*/
ponto2D* criar();

/*
Insere um item no fim da lista
Entrada: lista sequencial P e o valores a serem enseridos
Saída: verdadeiro se item foi inserido; falso caso contrário
*/
bool inserir_fim(ponto2D* P, int x, int y);

/*
Entrada: lista P
Saída: tamanho da lista, ou seja, a quantidade de itens válidos
presentes na lista
*/
int tamanho(ponto2D *P);

/*
Entrada: lista P
Saída: verdadeiro se estiver vazia; falso caso contrário
*/
bool vazia(ponto2D *P);

/*
Entrada: lista P e matriz que representa o labirinto
Saída: Não tem
*/
void Anotar( ponto2D* P,int L[MAX][MAX]);

