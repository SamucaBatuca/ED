#define Tipo int
#define MAX 5
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
int menu();
int main(){
    int opcao;
    Tipo e;
    Pilha *p = criaPilha(MAX);
    opcao = menu();
    while(opcao!=0){
        switch(opcao){
            case 1:
                puts("Digite um inteiro para empilhar:");
                scanf("%d", &e);
                push(p, e);
            break;
            case 2:
                e = pop(p);
                printf("%d", e);
            break;
        }
        opcao = menu();
    }
    return 0;
}
int menu(){
    puts("1 - Empilhar");
    puts("2 - Desempilhar");
    puts("0 - Sair");
    puts("Digite a opção desejada:");
    int op;
    scanf("%d", &op);
    return op;
}