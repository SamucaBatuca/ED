#ifndef Fila_H
#define Fila_H
#endif

#include <stdio.h>
#include <stdlib.h>

#define Tipo int




typedef struct Fila
{
    Tipo *f;
    int qtd;
    int ini;
    int fim;
    int tamanho;
} Fila;

Fila * criaFila(int tam){ // retorna um poteiro do tipo Fila
    Fila *fi = malloc(sizeof(Fila)); // cria o ponteiro da Fila
    fi -> tamanho = tam; // define o tamanho
    fi -> qtd = 0; // zera
    fi -> ini = 0; // define onde começa (inicialmente na posição zero)
    fi -> fim = -1; // define o final (como ta vazio inicialmente, então é -1)
    fi -> f = malloc(sizeof(Tipo)*tam); // cria os espaços para armazenar na Fila
}

void push (Fila *fi, Tipo val){
    if (fi!= NULL){ // ve se a Fila existe
        if (fi -> tamanho == fi -> qtd){ // se o tamanho da Filha não estourou
            puts ("Fila cheia");
            return;
        }
        fi -> fim++; // o fim da fila anda
        *((fi->f)+ fi -> fim) = val;
        /* Isso significa: aponte para o ponteiro do slot de variáveis da
            Fila somado ao fim (ou seja, aponta pro fim) e insira nele
            uma variável do tipo anteriormente definido 
        */
        fi -> qtd++; // adiciona mais um à quantidade
    }
    return;
}


Tipo pop(Fila* fi){
    Tipo e; // informação a ser retornada
    if(fi != NULL ){ // se existe a fila
        if(fi->qtd!=0){ // se ela já não estiver vazia
            fi->qtd--; // diminue a quantidade de elementos
            e = *((fi->f)+fi->ini); // o retorno vai receber o começo da fila
            fi->ini++;
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




/*int main() {
    Tipo i;
    Fila *f = criaFila(5);

    for(i=0; i<5; i++){
        push(f, i);
        printf("%d\n", i);
    }

    while(f->qtd != 0){
        Tipo aux = pop(f);
        printf("\n%d", aux);
    }

    return 0;
}*/
