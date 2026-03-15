#include <stdio.h>
#include <stdlib.h>
#include "PILHA.h"
#define Tipo int


int main (){
    int aux, n, i;

    printf("Digite um numero inteiro para a convercao binaria: ");
    scanf("%d", &n);

    Pilha *p = criaPilha(32);
   
   
   
    while(n){
        if (n == 1){
            aux = n;
        } else {
            aux = n % 2;
        }
        n = n/2;
        push(p, aux);

    }

    printf("O nomero em questao eh escrito desta forma em binario: ");
    while(p->qtde != 0){
        aux = pop(p);
        printf("%d", aux);
    }


}
