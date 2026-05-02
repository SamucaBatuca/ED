#include <stdio.h>
#include <stdlib.h>
#include "DequeElemento.h"
#include "ListaEncadeada.h"


Elemento * achaLink(LinkedList * l1, LinkedList * l2){
    if(l1 == NULL){puts("lista 1 inexistente"); return NULL;}
    if(l2 == NULL){puts("Lista 2 inexistente"); return NULL;}
    if(l1 -> qntd == 0){puts("Lista 1 vazia"); return NULL;}
    if(l2 -> qntd == 0){ puts("Lista 2 vazia"); return NULL;}


    Elemento * el, * i = l1 -> primeiro, * j = l2 -> primeiro;
    Deque * fila2;
    int cont =0;

    if(l1->qntd < l2->qntd){fila2=criaDeque(l2->qntd);}
    else{fila2 = criaDeque(l1->qntd);}

    while(j != NULL){
        pushBackE(fila2, j);
        j = j->proximo;
    }

    while(cont < fila2->tamanho){       // Rola na fila2 a lista 1 até achar um endereço igual (O(n²))
        while(i != NULL){
            if(i == *(fila2->d + cont)){puts("Link encontrado"); return i;}
            i= i->proximo;
        }
        i = l1->primeiro;
        cont++;
    }

    puts("Nenhum link encontrado");
    return NULL;


}





int main(){

    LinkedList *l1 = criaLista();
    LinkedList *l2 = criaLista();
    

    Elemento *e, *aux1, *aux2; 
    int i, j=0;

    for(i = 0; i<3; i++){
        e = criaElemento(j);
        pushBack(l1,e);
        printf("%d \n", e -> valor);
        if(i == 2){aux1 = e;}
        e = NULL;
        j += 2;  
    }


    j=1;

    for(i = 0; i<3; i++){
        e = criaElemento(j);
        pushBack(l2,e);
        if(i == 1){aux2 = e;}
        e = NULL;
        j += 2;
        printf("%d \n", j);
    }
    aux1->proximo = aux2;       // Cria o link

    e = achaLink(l1, l2);

    printf("\n%d\n", e->valor);
  




}