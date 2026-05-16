#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"
#include "ListaEncadeadaE.h"
#include "ListaEncadeada.h"


Elemento * verCiclo(LinkedList * l1){
    LinkedListE * aux = criaListaE();
    ElementoE * el, * pri;
    Elemento * e;
    

    for(e = l1->primeiro; e != NULL; e = e->proximo){
        el = criaElementoE(e);
        // Procura valor na lista
        for(pri = aux->primeiro; pri!=NULL; pri = pri->proximo){
            if(el->valor == pri->valor){
                puts("Ciclo encontrado");
                return el->valor;
            }
            
        }    
        pushBackE(aux, el);      // Adiciona na fila        
    }
    puts("Ciclo nao encontrado");
    return NULL;
}





int main(){
    LinkedList *l1 = criaLista();
    LinkedList *l2 = criaLista();
    Elemento *e; 
    int i, aux;

    for(i = 0; i<6; i++){
        e = criaElemento(i);
        pushBack(l1,e);
        printf("%d \n", e -> valor);
    }

    while(i<12){
        e = criaElemento(i);
        pushBack(l2,e);
        printf("%d \n", e -> valor);
        i++;
    }


    e->proximo = l2->primeiro->proximo->proximo->proximo;               // Liga l2 no quarto elemento (9), criando o clico
    
    e = l1->primeiro->proximo->proximo->proximo->proximo->proximo;      // Pega o último elemento de l1
    e->proximo = l2->primeiro->proximo->proximo->proximo->proximo;      // Linka l1 no quinto elemento (10) de l2, criando o ciclo
   

    e = verCiclo(l1);
    printf("Comeco do cilco de L1 eh no valor: %d\n", e->valor);

    e = verCiclo(l2);
    printf("Comeco do cilco de L2 eh no valor: %d\n", e->valor);

}