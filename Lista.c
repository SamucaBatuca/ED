#include <stdio.h>
#include <stdlib.h>

#define Tipo int

typedef struct Lista
{
    Tipo *l;
    int qtd;
    int ini;
    int fim;
    int tamanho;
    int posicao;
} Lista;

Lista * criaLista(int tam){ // retorna um poteiro do tipo Fila
    Lista *li = malloc(sizeof(Lista)); // cria o ponteiro da Fila
    li -> tamanho = tam; // define o tamanho
    li -> qtd = 0; // zera
    li -> ini = 0; // define onde começa (inicialmente na posição zero)
    li -> fim = -1; // define o final (como ta vazio inicialmente, então é -1)
    li -> posicao = 0;
    li -> l = malloc(sizeof(Tipo)*tam); // cria os espaços para armazenar na Fila
}

void push (Lista *li, Tipo val){
    if (li!= NULL){ // ve se a Fila existe
        if (li -> tamanho == li -> qtd){ // se o tamanho da Filha não estourou
            puts ("Fila cheia");
            return;
        }
        li -> fim++; // o fim da fila anda
        *((li->l)+ li -> fim) = val;
        /* Isso significa: aponte para o ponteiro do slot de variáveis da
            Fila somado ao fim (ou seja, aponta pro fim) e insira nele
            uma variável do tipo anteriormente definido 
        */
        li -> qtd++; // adiciona mais um à quantidade
    }
    return;
}


Tipo pop(Lista* li){
    Tipo e; // informação a ser retornada
    if(li != NULL ){ // se existe a fila
        if(li->qtd!=0){ // se ela já não estiver vazia
            li->qtd--; // diminue a quantidade de elementos
            e = *((li->l)+li->ini); // o retorno vai receber o começo da fila
            li->ini++;
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




int main() {
    Tipo i;
    Lista *li = criaLista(5);

    for(i=0; i<5; i++){
        push(li, i);
        printf("%d\n", i);
    }

    while(li->qtd != 0){
        Tipo aux = pop(li);
        printf("\n%d", aux);
    }

    return 0;
}
