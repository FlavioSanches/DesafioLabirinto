#include <stdlib.h>
#include <stdio.h>
#include "fila_p.h"

#define CAPACIDADE 25
#define MAX 7

struct cordenadas {
    float x, y;
};

struct ponto {
    struct cordenadas cord[CAPACIDADE];
    int qtde, cap;
};

typedef struct ponto ponto2D;

int capacidade(ponto2D* P) {
    return P->cap;
}

bool cheia(ponto2D* P) {
    if (P->qtde == P->cap)
        return true;

    return false;
}

ponto2D* criar() {
    ponto2D* nova = (ponto2D*)malloc(sizeof(ponto2D));
    if (nova != NULL) {
        nova->qtde = 0;
        nova->cap = CAPACIDADE;
    }

    return nova;
    
}

bool inserir_fim(ponto2D* P, int x, int y) {
   
    if (cheia(P))
        return false;

    P->cord[P->qtde].x = x;
    P->cord[P->qtde].y = y;
    P->qtde++;

    return true;
}

int tamanho(ponto2D* P) {
    return P->qtde;
}

bool vazia(ponto2D* P) {
    if (P->qtde == 0)
        return true;

    return false;
}

void Anotar( ponto2D* P,int L[MAX][MAX]) {
    
    L[1][1] = 1;//comecar  com o valor 1 na posição L[1][1] para tratar o erro de começar com o valor 0 na posição L[1][1]
   
     
    
    inserir_fim(P,1,1); // começar o caminho na posição L[1][1]



   while (!vazia(P)) { // enquando a fila nao estiver vazia
        int i = P->cord[0].x; // para corderardas x
        int j = P->cord[0].y; // para corderardas y

        for (int k = 1; k < P->qtde; k++) { // substituir o valor atual pelo proximo valor
            P->cord[k - 1].x = P->cord[k].x;
            P->cord[k - 1].y = P->cord[k].y;
        }

        P->qtde--; 

        // verifica as posições adjantes onde os valores das cordenadas L[x][y] = 0 e depois incere no fim quando encontra 
        if (i - 1 >= 0 && L[i - 1][j] == 0) {
            L[i - 1][j] = L[i][j] + 1;
            inserir_fim(P, i - 1, j);
        }

        if (i + 1 < MAX && L[i + 1][j] == 0) {
            L[i + 1][j] = L[i][j] + 1;
            inserir_fim(P, i + 1, j);
        }

        if (j - 1 >= 0 && L[i][j - 1] == 0) {
            L[i][j - 1] = L[i][j] + 1;
            inserir_fim(P, i, j - 1);
        }

        if (j + 1 < MAX && L[i][j + 1] == 0) {
            L[i][j + 1] = L[i][j] + 1;
            inserir_fim(P, i, j + 1);
        }
    }

    free(P);
}










