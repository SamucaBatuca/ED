#ifndef MATRIZESPARCA_H
#define MATRIZESPARCA_H

#include <stdio.h>
#include <stdlib.h>

/*
Essa estrutura cria uma matriz que guarda elementos diferntes de elementos imensamente
repetidos. Sendo assim, ao adicionar ou conferir elementos nesta matriz, ele criará nós 
e adiciona apenas valores diferentes dos massivamente repetidos.
*/



// Struct para representar um nó da matriz de listas encadeadas
typedef struct tempNO{
    float valor;            // salva o valor do elemento
    int coluna;             // salva sua coluna   
    struct tempNO *prox;    // aponta pro proximo naquela linha
} NO;

typedef NO * Elemento; // faz um ponteiro de ponteiro que aponta para o inicio da linha

typedef struct matriz{
    Elemento * A;       // ponteiro que aponta para o começo da linha
    int linhas;     // salva a quantidade de linhas
    int colunas;    // salva a quantidade de colunas
} Matriz;

void criaMatriz (Matriz *mat, int lin, int col){
    int i;
    mat->linhas = lin;
    mat->colunas = col;
    mat->A = (Elemento *) malloc(lin * sizeof(Elemento));   // cria arranjos equivalentes ao numero de linhas
    for(i=0; i<lin;i++){mat->A[i] = NULL;}      // inicializa cada começo como NULL, pois está vazio
}

void pushMat(Matriz * mat, int lin, int col, float val){
    if(mat == NULL){ puts("Matriz não existe"); return;}
    if(col<0 || lin <0 || lin >= mat->linhas || col >= mat->colunas){ puts("Posição inválida"); return;}
    
    Elemento ant = NULL;                // salva a posição anterior
    Elemento atual = mat->A[lin];       // acessa a linha desejada

    // verifica se o elemento já existe na matriz esparça
    while(atual != NULL && atual->coluna < col){    // percorre a linha até encontrar a posição correta
        ant = atual;           // salva a posição anterior
        atual = atual->prox;   // avança para o próximo elemento
    }

    // verifica se achou o elemento
    if(atual != NULL && atual -> coluna == col){
        // se o valor a ser inserido for zero, remove da matriz
        if(val == 0){     
            if (ant == NULL) mat->A[lin] = atual -> prox;  // se for o primeiro da linha, ele recebe o proximo
            else ant -> prox = atual -> prox;              // se não, o anterior aponta para o próximo, removendo o atual
            free(atual);                                   // libera a memória do elemento removido
        } else {         // caso contrário, atualiza o valor do elemento existente
            atual -> valor = val;    
        } 

    } else{
        Elemento novo = (Elemento) malloc(sizeof(NO));   // cria um novo elemento
        novo -> valor = val;                  // atribui o valor
        novo -> coluna = col;                 // atribui a coluna
        novo -> prox = atual;                 // o próximo do novo elemento é o atual
        if(ant == NULL) mat->A[lin] = novo;   // se for oprimeiro elemento da linha
        else ant -> prox = novo;              // se não, o anterior aponta para o novo

    }
    return;
}

float getMat(Matriz * mat, int lin, int col){
    if(mat == NULL){ puts("Matriz não existe"); return ;}
    if(col<0 || lin <0 || lin >= mat->linhas || col >= mat->colunas){ puts("Posição inválida"); return 0;}

    Elemento atual = mat -> A[lin];     // acessa a linha desejada
    while (atual != NULL && atual -> coluna < col){
        atual = atual -> prox;   // percorre a linha até encontrar a posição correta
    }

    if(atual != NULL && atual -> coluna == col){return atual -> valor;}    // se encontrar, retorna o elemento
    else return 0;      // se não encontrar, retorna zero, pois é uma matriz esparça
}

#endif