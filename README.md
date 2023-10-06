# DesafioLabirinto

Aluno: Flávio Alves Sanches

Curso: Engenharia de Computação

Displina: Laboratorio de Estrutura de Dados

Periodo: 2º

Professor: Anderson Grandi Pires

Projeto Pratico: Melhor (menor) caminho em um labirinto

Linguagem utilizada : C

***Descrição***

Executada a anotação do labirinto,para encontrar um menor caminho, na matriz L o número mínimo de passos necessários para atingir cada uma das posições do labirinto, a partir da entrada.

***Procedimento***

Foi desenvolvido em um arquivo no formato txt (labinto_entrada.txt) recebendo os caracteres '#' para reperesentar a parede do labirinto e '.' para represenatar o caminho com "-1" e "0" convertido para 
o arquivo txt "labirinto_saida" e depois foi realizado a leitura desse arquivo txt e imprimdo na tela de apresentação e por fim foi feito a leitura do mesmo arquivo e apresentado na tela de apresentação os valor -1 para '#' e 0 para '.', depois foi criada uma codigo aproveitado fila.h e fila.c 
para uma fila de cordenadas x e y desenvolvendo o algoritmo de anotar a matriz com o caminho onde a L [x][y] = k  indica que são necessários k passos para alcançar a posição (i, j) a partir da célula
de entrada. 

***Copilação***

Compilação: gcc gerar_labirinto.c fila_p.c

Execução no Windows: ./a.exe

Execução no Linux: ./a.out
