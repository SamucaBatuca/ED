#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"
#include "ListaEncadeada.h"


Elemento * verCiclo(LinkedList * l1){
    Deque * aux = criaDeque(l1->qntd);
    Elemento * el;
    int i = 0;
    for(el=l1->primeiro; el != NULL; el= el->proximo){
        while(i < aux->qtd){            // Procura valor na fila
            if(el->valor == *((aux->d)+i)){
                puts("Ciclo encontrado");
                return el;
            }
            i++;
        }
        pushBackD(aux, el->valor);      // Adiciona na fila
        i=0;
    }
    puts("Ciclo nao encontrado");
    return NULL;
}





int main(){
    LinkedList *l1 = criaLista();
    Elemento *e; 
    int i, aux;

    for(i = 0; i<6; i++){
        e = criaElemento(i);
        pushBack(l1,e);
        printf("%d \n", e -> valor);
    }

    e->proximo = l1->primeiro->proximo->proximo;
    printf("\n%d\n\n", e->proximo->valor);

    e = verCiclo(l1);
    printf("Comeco do cilco: %d\n", e->valor);

    
}