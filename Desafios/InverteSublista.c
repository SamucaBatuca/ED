#include <stdio.h>
#include <stdlib.h>
#include "pilhaElemento.h"
#include "ListaEncadeada.h"


void inverter(LinkedList * l1, int s, int f){

    Elemento * aux, * seg;
    Pilha * pi = criaPilha(f-s);
    int i;

    for(i=0, aux = l1->primeiro; i != s; i++){      // Vasculha até o começo
        aux = aux->proximo;
    }

    while(i < f){                                   // Empilha para inverter
        push(pi, aux);
        seg = aux = aux->proximo;
        i++;
    }

    // Se começar no primeiro elemento da lista
    if(s-1<0){      
        aux = pop(pi);
        l1->primeiro->proximo = aux;
        while(pi->qtde != 0){                       // Inverte
            aux->proximo = pop(pi);
            aux = aux->proximo;                     // Aponta pro fim
        }
        aux->proximo = seg; 
    // Se não é o primeiro, então procura o começo da troca        
    } else {        
        for(i=0, aux = l1->primeiro; i != s-1; i++){
            aux = aux->proximo;
        }

        while(pi->qtde != 0){
            aux->proximo = pop(pi);
            aux = aux->proximo;
        }
        aux->proximo = seg; 
    }

}



int main(){
    LinkedList *l1 = criaLista();
    Elemento *e; 
    int i, j, s, f, aux;

    printf("Digite quantos elementos a lista tera: ");
    scanf("%d", &j);

    for(i = 0; i<j; i++){
        e = criaElemento(i);
        pushBack(l1,e);
        printf("%d \n", e -> valor);
        e = NULL;  
    }

    printf("Em uma lista de %d elementos, selecione o ponto inicial da inversao:\n", j);
    scanf("%d", &s);
    printf("Em uma lista de %d elementos, selecione o ponto final da inversao:\n", j);
    scanf("%d", &f);
    while(f > l1-> qntd || s> f){
        printf("Valores incorretos! \nPor gentileza, coloque os respectivos valores de incio e fim coerentes para uma lista de %d elementos!\n", j);
        scanf("%d %d",&s, &f);
    }
   
   inverter(l1, s-1, f);
   listar(l1);

    
}