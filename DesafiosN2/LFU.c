#include "LinkedListDC.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct LFU_cache
{
    int tam;
    int qntd;
    LinkedListD * LFU;
    LinkedListD * LRU;      // Nesta lista de ocorrência, o primeiro elemento é o ultimo frequêntado
}LFU_cache;


LFU_cache * criaCache(int capacidade){
    LFU_cache * cache = (LFU_cache*)malloc(sizeof(LFU_cache));
    cache -> LRU = criaListaD();
    cache -> tam = capacidade;
    cache -> LFU = criaListaD();
    cache -> qntd = 0;
    return cache;
}


void cache_put(LFU_cache* cache, int valor){
    if(cache == NULL){puts("Cache inexistente"); return;}
    
    ElementoC * el = criaElementoC(valor);          // Cria um elemento
    el -> vis++;                                    // Aumenta a recorrencia
    ElementoC * aux = criaElementoC(valor);         // Cria o elemento da recorrencia
    
    

    // Se a lista estiver cheia
    if(cache -> qntd == cache->tam){
        ElementoC * ref = popBackD(cache->LRU);     // Pega a menor ocorrencia
        
        
        // Percorre a lista até achar o menos ocorrente
        for(aux = cache -> LFU -> primeiro; aux != ref; aux = aux->proximo);

        // Encaixa o elemento no LFU
        aux -> anterior -> proximo = el;
        el->proximo = aux -> proximo;
        if(aux -> proximo != NULL){
            aux -> proximo -> anterior = el;
        }

        
        pushInicioD(cache->LRU, el);
        
        // Desliga o elemento de menor ocorrência
        //aux = NULL;

    // Caso normal
    } else {
        pushBackD(cache -> LFU, el);                 // Da push nele no cache
        pushInicioD(cache -> LRU, aux);               // Da push na ocorrência


        /*//printf("\n%d\n", cache->LFU->primeiro->valor);
        ElementoC * i;
        for (i = cache->LFU->primeiro; i != NULL; i = i -> proximo){
            printf("%d - ", i-> valor);
        }
        printf("NULL\n");
        
        

        
        for (i = cache->LRU->primeiro; i != NULL; i = i -> proximo){
            printf("%d - ", i-> valor);
            
        }
        printf("NULL\n");*/

        cache -> qntd++;
    }

}


int cache_get(LFU_cache* cache, int chave){

    ElementoC * ref = criaElementoC(chave);
    ElementoC * aux;

    // Procura a referência
    for(aux = cache -> LFU -> primeiro; aux != ref; aux = aux->proximo);

    // Caso ache a referência
    if (aux != NULL){
        aux -> vis++;
        pushInicioD(cache -> LRU, aux);

        // Procura o elemento na ocorrência
        for(aux = cache -> LRU -> primeiro-> proximo; aux != ref; aux = aux->proximo);
        aux -> anterior -> proximo = aux -> proximo;
        if(aux -> proximo != NULL){
            aux -> proximo -> anterior = aux -> anterior;
        }
        aux = NULL;
        return cache -> LRU -> primeiro -> valor;
    } else{
        return -1;
    }

}


void destruir_cache(LFU_cache * cache){

}








int main()
{
    LFU_cache * cache = criaCache(4);
    cache_put(cache, 4);
    cache_put(cache, 3);
    cache_put(cache, 2);
    cache_put(cache, 1);
    //cache_get(cache, 3);
    //cache_get(cache, 4);
    //cache_get(cache, 4);
    //cache_put(cache, 5);
    
    listarD(cache->LFU);
    listarD(cache->LRU);

}

