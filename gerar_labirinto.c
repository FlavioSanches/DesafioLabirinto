#include <stdio.h>
#include <stdlib.h>
#include "fila_p.h"

#define MAX 7



    
    
//definição da estrutura da fila de pontos


int main(){

    ponto2D *p1 = criar();
     

    FILE* arq_leitura1 = fopen("labirinto_entrada.txt", "r"); // Abrir o arquivo em mode de leituira
    if(arq_leitura1 == NULL){
        printf("Erro ao abrir.\n");
        exit(0);
    }

    // Imprime o arquivo inteiro
    char caracterex;
    while(fscanf(arq_leitura1, "%c", &caracterex) != EOF) 
        printf("%c", caracterex);

    // Imprime a primeira linha
    fscanf(arq_leitura1, "%c", &caracterex);
    while(caracterex != '\n') {
        printf("%c", caracterex);
        fscanf(arq_leitura1, "%c", &caracterex);
    }
    fclose(arq_leitura1);

    printf("\n     Convercao do labirinto! \n");



    FILE* arq_entrada = fopen("labirinto_entrada.txt", "r");    // Abrir o arquivo em mode de leituira
    FILE* arq_saida = fopen("labirinto_saida.txt", "w"); // Abrir o arquivo em mode de escrita

    if (arq_entrada == NULL || arq_saida  == NULL ) { 
        printf("Erro ao abrir.\n");
        exit(0);
    }

    int caractere;
    //pecorre o arquivo de entrada e escreve no arquivo de saida -1 para # e 0 para .
    while ((caractere = fgetc(arq_entrada)) != EOF) {
        if (caractere == '#') {
            fprintf(arq_saida , "-1");
        } else if (caractere == '.') {
            fprintf(arq_saida , " 0");
        } else {
            fputc(caractere, arq_saida );
        }
    }

    fclose(arq_entrada);
    fclose(arq_saida );

    int mat[MAX][MAX];  

    
    FILE *arq_leitura2 = fopen("labirinto_saida.txt", "r"); // Abrir o arquivo em mode de leituira

    // Verificar se o arquivo foi aberto com sucesso
    if (arq_leitura2 == NULL) {
        printf("Erro ao abrir.\n");
    }

     // pecorre todo o arquivo de texto com a função fscan para jogar os seus valores na matriz 
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            fscanf(arq_leitura2, " %d", &mat[i][j]);
        }
    }

    int x = -1; //  trocar o valor de '#' 
    int y = 0;  // trocar o valor de '.'  
    // Pecorre a toda a matriz para imprimir na tela de apresentação os valores de -1 e 0 
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if(mat[i][j] == -1)
                printf("%d ",mat[i][j]);
            else{
                printf(" %d ",mat[i][j]);
            }
        }
        printf("\n");
    }

    // Fechar o arquivo de texto
    fclose(arq_leitura2);

    printf("\n\n\n");
    
    // Chame a função Anotar passando o ponto2D e a matriz mat[7][7]
    Anotar(p1,mat);
    
    // Imprimindo a matriz com a anotação do caminho
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if(mat[i][j] == -1 || mat[i][j] >=10) // condição para ajustar o espacamento entre os numeros
                printf("%d ", mat[i][j]);
            else{
                printf(" %d ", mat[i][j]);
            }
        }
        printf("\n");
    }
 
    return 0;
}

    
    