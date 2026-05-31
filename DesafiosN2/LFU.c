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


    ElementoC *aux;
    int posi = 0; 

    // Procura o elemento dentro de LFU
    for (aux = cache->LFU->primeiro;aux != NULL && aux->valor != valor; aux = aux->proximo);

    // Se achar o elemento, já faz um "get" dele
    if (aux != NULL) {
        aux->vis++;                     // Aumenta a visitação
        
        aux = cache->LRU->primeiro;     // Pega o menos recorrente

        while (aux != NULL && aux->valor != valor) {
            aux = aux->proximo;
            posi++;                     // Salva posição
        }
        
        if (aux != NULL) {
            // Remove de forma segura baseado na posição encontrada
            ElementoC *movido;
            if (posi == 0) {
                movido = popInicioD(cache->LRU);
            } else if (posi == cache->LRU->qtde - 1) {
                movido = popBackD(cache->LRU);
            } else {
                movido = popPosiD(cache->LRU, posi);
            }
            // Reinsere no final da LRU (Mais recente)
            pushBackD(cache->LRU, movido);
        }
        return; 
    }
    
    

    // Se a lista estiver cheia
    if(cache -> qntd == cache->tam){

        aux = cache->LRU->primeiro;
        int min = aux->vis;
        int alvo = 0;

        posi = 0;
        ElementoC *curr = cache->LRU->primeiro;     // Elemento cursor que servirá para fazer a busca

        // Procura o menor visitado
        while (curr != NULL) {
            if (curr->vis < min) {
                min = curr->vis;
                aux = curr;                         // Aux se torna o menos visitado
                alvo = posi;                        // Guarda o índice do alvo
                printf("Salvei o menos visitado\n");
            }
            curr = curr->proximo;
            posi++;
        }

        int temp = aux->valor;                      // Valor de referência temporário

        // Se tiver no ínicio
        if (alvo == 0) {
            popInicioD(cache->LRU);
        // Se for o último
        } else if (alvo == cache->LRU->qtde - 1) {
            popBackD(cache->LRU);
        // Outro caso
        } else {
            popPosiD(cache->LRU, alvo);
        }
    
        // Agora vai remover de LFU
        aux = cache->LFU->primeiro;    
        posi = 0;
        // Procura o valor que será removido    
        while (aux != NULL && aux->valor != temp) {
            aux = aux->proximo;
            posi++;
        }

        if (aux != NULL) {
            // Se estiver no começo
            if (posi == 0) { popInicioD(cache->LFU);
            // Se estiver no fim
            } else if (posi == cache->LFU->qtde - 1) { popBackD(cache->LFU);
            // Outro caso
            } else { popPosiD(cache->LFU, posi);}
        }

        cache->qntd--;

    }

    // Caso normal

    aux = criaElementoC(valor);
    aux->vis = 1;
    pushBackD(cache->LFU, aux);
    
    aux = criaElementoC(valor);
    aux->vis = 1;
    pushBackD(cache->LRU, aux);
    
    cache->qntd++;

}


int cache_get(LFU_cache* cache, int chave){

    // Se algum valor for nulo
    if (cache == NULL || cache->LFU == NULL || cache->LRU == NULL) {
        return -1;
    }

    ElementoC *aux = cache->LFU->primeiro;
    int posi = 0;

    // Procura o elemento
    while (aux != NULL && aux->valor != chave) {
        aux = aux->proximo;
    }

    // Se o elemento não existir
    if (aux == NULL) {return -1;}

    aux->vis++;
    aux = cache->LRU->primeiro;
    posi = 0;
    // Procura em LRU
    while (aux != NULL && aux->valor != chave) {
        aux = aux->proximo;
        posi++;
    }

    // Realoca em LRU
    if (aux != NULL) {
        ElementoC *movido;
        //
        if (posi == 0) { movido = popInicioD(cache->LRU);}
        else if (posi == cache->LRU->qtde - 1) { movido = popBackD(cache->LRU);}
        else { movido = popPosiD(cache->LRU, posi);}
        
        pushBackD(cache->LRU, movido);
    }

    return chave;


    /*ElementoC * ref = criaElementoC(chave);
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
    }*/

}


void destruir_cache(LFU_cache * cache){

    // Se o cache já for nulo, não há nada para apagar
    if (cache == NULL) {
        return;
    }

    ElementoC *aux = NULL;

    //Limpa todos os elementos de LFU
    if (cache->LFU != NULL) {
        while (cache->LFU->qtde > 0) {
            aux = popInicioD(cache->LFU); //
            if (aux != NULL) {
                free(aux);
            }
        }
        // Libera a estrutura
        free(cache->LFU);
    }

    //Limpa todos os elementos de LRU
    if (cache->LRU != NULL) {
        while (cache->LRU->qtde > 0) {
            aux = popInicioD(cache->LRU); //
            if (aux != NULL) {
                free(aux);
            }
        }
        // Libera a estrutura
        free(cache->LRU);
    }

    //Libera a estrutura do cache em si
    free(cache);
    
    puts("Cache e dependencias liberados com sucesso da memoria.");

}








int main()
{
    LFU_cache * cache = criaCache(4);
    cache_put(cache, 4);
    cache_put(cache, 3);
    cache_put(cache, 2);
    cache_put(cache, 4);
    cache_put(cache, 1);
    cache_get(cache, 3);
    cache_get(cache, 4);
    cache_get(cache, 4);
    cache_put(cache, 5);
    
    listarD(cache->LFU);
    listarD(cache->LRU);

    destruir_cache(cache);

    listarD(cache->LFU);
    listarD(cache->LRU);

}

