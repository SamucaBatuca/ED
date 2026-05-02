#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"


LinkedList * ordenaLista(LinkedList * l1, LinkedList * l2){

    


    if(l1 == NULL){puts("lista 1 inexistente"); return NULL;}
    if(l2 == NULL){puts("Lista 2 inexistente"); return NULL;}
    if(l1 -> qntd == 0){return l2;}
    if(l2 -> qntd == 0){return l1;}

    Elemento * el, * i = l1 -> primeiro, * j = l2 -> primeiro;


    if(i->valor < j->valor){                        // Decide qual dos dois inícios é o menor
        el = i;
        i = i -> proximo;
        if(l1->qntd == 1){el-> proximo = j;}        // Se a lista tiver apenas 1 elemento, basta conecta-lo no começo da segunda
    }        
    else {
        el = j;
        j = j -> proximo;
        if(l2 -> qntd == 1){el-> proximo = i;}
    }          


    while(el != NULL){
        if(i == NULL){                  // Testa se chegou ao fim
            el -> proximo = j;
            el = i;
        } else{
            if(i-> valor < j -> valor){
                el -> proximo = i;      // Aponta pro menor
                el = i;                 // Se torna o menor
                i = i -> proximo;       // Avança a lista
            } else {
                if(j == NULL){          // Testa se chegou ao fim
                    el -> proximo = i;
                    el = j;
                } else {
                    el -> proximo = j;
                    el = j;
                    j = j -> proximo;
                }
               
                
            }
            
        }
        
       
           
        
    }
    if(l1 -> primeiro < l2 -> primeiro){return l1;}
    else {return l2;}

}





int main(){
    LinkedList *l1 = criaLista();
    LinkedList *l2 = criaLista();
    LinkedList *lf;

    Elemento *e; 
    int i, j=0;

    for(i = 0; i<3; i++){
        e = criaElemento(j);
        pushBack(l1,e);
        printf("%d \n", e -> valor);
        e = NULL;
        j += 2;  
    }

    printf("\n%d\n\n", l1 -> primeiro -> valor);

    j=1;

    for(i = 0; i<3; i++){
        e = criaElemento(j);
        pushBack(l2,e);
        e = NULL;
        j += 2;
        printf("%d \n", j);
    }

    lf = ordenaLista(l1,l2);
    listar(lf);




}