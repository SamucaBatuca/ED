#include <stdio.h>

#define Tipo int

typedef struct pilha
{
    Tipo *p;
    int qtd;
    int topo;
    int tamanho;    
} Pilha;

Pilha * criaPilha(int tam){ // retorna um poteiro do tipo Pilha
    Pilha *pi = malloc(sizeof(Pilha)); // cria o ponteiro da Pilha
    pi -> tamanho = tam; // define o tamanho
    pi -> qtd = 0; // zera
    pi -> topo = -1; // aponta pro fim (inicialmente vazio)
    pi -> p = malloc(sizeof(Tipo)*tam); // cria os espaços para armazenar na pilha
}

void push (Pilha *pi, Tipo val){
    if (pi!= NULL){ // ve se a pilha existe
        if (pi -> tamanho == pi -> qtd){ // se o tamanho da pilha não estourou
            puts ("Pilha cheia");
            return;
        }
        pi -> topo++; // o topo sobe
        *((pi->p)+ pi -> topo) = val;
        /* Isso significa: aponte para o ponteiro do slot de variáveis da
            pilha somado ao topo (ou seja, aponta pro topo) e insira nele
            uma variável do tipo anteriormente definido 
        */
        pi -> qtd++; // adiciona mais um à quantidade
    }
    return;
}






int main() {
    Pilha *p = criaPilha(5);

    return 0;
}
