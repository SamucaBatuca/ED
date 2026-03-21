#ifndef FilaC_H
#define FilaC_H
#endif

#include <stdio.h>
#include <stdlib.h>

#define Tipo int



typedef struct FilaC
{
    Tipo *fc;
    int qtd;
    int iarm;
    int ilei;
    int tamanho;
} FilaC;


FilaC * criaFilaC(int tam){ // retorna um poteiro do tipo Fila
    FilaC *fic = malloc(sizeof(FilaC)); // cria o ponteiro da Fila
    fic -> tamanho = tam; // define o tamanho
    fic -> qtd = 0; // zera
    fic -> iarm = 0; // define onde começa o armazenamento (inicialmente na posição zero)
    fic -> ilei = 0; // define onde começa a leitura (inicialmente na posição zero)
    fic -> fc = malloc(sizeof(Tipo)*tam); // cria os espaços para armazenar na Fila
}

void push (FilaC *fic, Tipo val){
    if (fic!= NULL){ // ve se a Fila existe
        if (fic -> tamanho == fic -> qtd){ // se o tamanho da Fila não estourou
            puts ("Fila cheia");
            return;
        }
        *((fic->fc)+ fic -> iarm) = val;
        /* O ponteiro desloca para a posição de armazenamento e lá
           armazena o valor
        */
        fic -> iarm = (fic-> iarm+1) % fic->tamanho ; 
        /* A posição de armazenamento desloca-se para o endereço
           especificado pelo cálculo usando o tamanho da fila.
           Assim, quando ele chega no endereço final, ele volta a
           apontar para a posição 0.
        */
        fic -> qtd++; // adiciona mais um à quantidade
    }
    return;
}


Tipo pop(FilaC* fic){
    Tipo e; // informação a ser retornada
    if(fic != NULL ){ // se existe a fila
        if(fic->qtd!=0){ // se ela já não estiver vazia
            e = *((fic->fc)+fic->ilei); // o retorno vai receber a informação da leitura
            fic -> ilei = (fic-> ilei+1)% fic->tamanho ; // a leitura recebe a próxima posição
            fic->qtd--; // diminue a quantidade de elementos

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


/*

    Código de teste da biblioteca:


int main() {
    Tipo i;
    FilaC *fic = criaFilaC(3);

    for(i=0; i<3; i++){
        push(fic, i);
        printf("%d %d\n", i, fic->fc + fic->iarm-1);
    }

    while(fic->qtd != 0){
        Tipo aux = pop(fic);
        printf("\n%d %d", aux, fic->fc + fic->ilei-1);
    }

    return 0;
}

*/

