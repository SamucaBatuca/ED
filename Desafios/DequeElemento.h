#ifndef DequeElemento_h
#define DequeElemento_h

#include "ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

#define Tipo Elemento

typedef struct Deque
{
    Tipo ** d;
    int qtd;
    int front;
    int back;
    int tamanho;
} Deque;

Deque * criaDeque(int tam){ // retorna um poteiro do tipo Fila
    Deque *deq = malloc(sizeof(Deque)); // cria o ponteiro da Fila
    deq -> tamanho = tam; // define o tamanho
    deq -> qtd = 0; // zera
    deq -> front = 0; // define onde começa (inicialmente na posição zero)
    deq -> back = -1; // define o final (como ta vazio inicialmente, então é -1)
    deq -> d = malloc(sizeof(Tipo*) * tam); // cria os espaços para armazenar na Fila
}

void pushBackE(Deque *deq, Tipo * val){
    if (deq!= NULL){ 
        if (deq -> tamanho == deq -> qtd){ 
            puts ("Fila cheia");
            return;
        }
        deq -> back++;
        deq->d[deq -> back] = val;
        
        deq -> qtd++; 
    }
    return;
}

Tipo * popBackE(Deque* deq){
    Tipo * e; // informação a ser retornada
    if(deq != NULL ){ // se existe a fila
        if(deq->qtd!=0){ // se ela já não estiver vazia
            deq->qtd--; // diminue a quantidade de elementos
            e = deq->d[deq->back]; // o retorno vai receber o começo da fila
            deq->back--;
        }
        else{
            puts("Fila vazia"); // se estiver vazia, retorna isso
        }
    }
    else{
        puts("Essa fila não existe"); // se não existir fila
    }
    return e; // retorna a informação que será popada
}


Tipo * popFrontE(Deque* deq){
    Tipo * e; // informação a ser retornada
    if(deq != NULL ){ // se existe a fila
        if(deq->qtd!=0){ // se ela já não estiver vazia
            deq->qtd--; // diminue a quantidade de elementos
            e = deq->d[deq->front]; // o retorno vai receber o começo da fila
            deq->front++;
        }
        else{
            puts("Fila vazia"); // se estiver vazia, retorna isso
        }
    }
    else{
        puts("Essa fila não existe"); // se não existir fila
    }
    return e; // retorna a informação que será popada
}

void pushFrontE(Deque *deq, Tipo * val){
    if (deq!= NULL){ // ve se a Fila existe
        if (deq -> tamanho == deq -> qtd){ // se o tamanho da Fila não estourou
            puts ("Fila cheia");
            return;
        }
        deq -> back++; // o fim da fila anda
        int cont = 0;
        Tipo * aux;
        while((deq->back-cont) > (deq->front)){
            cont++;
            aux = deq->d[deq->back - cont];// pega valor da posição anterior a back
            deq->d[deq->back - (cont-1)] = aux; // insere a posição anterior no atual back
        }

        *(deq->d) = val; // atribuindo valor no front
        
        deq -> qtd++; // adiciona mais um à quantidade
    }
    return;
}

#endif