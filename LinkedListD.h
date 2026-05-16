#ifndef LikedListD_H
#define LikedListD_H
#include <stdlib.h>
#include <stdio.h>
typedef struct elemento
{
    int valor;
    struct elemento *proximo;
    struct elemento *anterior;
} Elemento;

typedef struct LinkedListD
{
    Elemento *primeiro;
    Elemento *ultimo;
    int qtde;
} LinkedListD;
// Primeiro da lista = Seu anterior = NULL
// Último da lista = Seu próximo = NULL


Elemento *criaElementoD(int val){
    Elemento *el = (Elemento *)malloc(sizeof(Elemento));
    el->valor = val;
    el->proximo = NULL;
    el->anterior = NULL;
    return el;
}


LinkedListD *criaListaD(){
    LinkedListD *lis = (LinkedListD*)malloc(sizeof(LinkedListD));
    lis->primeiro = NULL;
    lis->ultimo = NULL;
    lis->qtde = 0;
    return lis;
}


void pushInicioD(LinkedListD *lis, Elemento *el){
    if (lis == NULL || el == NULL){puts("Lista ou Elemento nulo(s)"); return;}
    
    if (lis->qtde == 0){                        // Lista vazia
            lis->primeiro = el;
            lis->ultimo = el;
        }
        else{                                   // Lista com elemento
            el->proximo = lis->primeiro;        // ligamos el à lista (primeiro)
            lis->primeiro->anterior = el;       // ligamos o primeiro (lista) ao el
            lis->primeiro = el;                 // modificamos o primeiro (lista) para ser o el
        }
        lis->qtde++;
    return;
}


Elemento *popInicioD(LinkedListD *lis){
    Elemento *aux = NULL;
    if (lis == NULL){puts("Lista nula"); return NULL;}
    if (lis->qtde == 0){puts("Lista Vazia"); return NULL;}
    
    aux = lis->primeiro;
    if (lis->qtde == 1){
        lis->primeiro = NULL;
        lis->ultimo = NULL;
    }
    else{
        lis->primeiro = lis->primeiro->proximo;     // Primeiro passa a ser o segundo
        lis->primeiro->anterior = NULL;             // Deligo a lista do aux
        aux->proximo = NULL;                        // Desligo o aux da lista
    }
    lis->qtde--;
    
    return aux;
}


void pushBackD(LinkedListD *lis, Elemento *el){
    if (lis == NULL || el == NULL){puts("Lista ou Elemento nulo(s)"); return;}
    
    if (lis->qtde == 0){
        lis->primeiro = el;
        lis->ultimo = el;
    }
    else{
        lis->ultimo->proximo = el;      // Liga a lista no el
        el->anterior = lis->ultimo;     // Liga o el na lista
        lis->ultimo = el;               // Altera o último da lista para o el
    }
    lis->qtde++;

}

Elemento *popBackD(LinkedListD *lis){
    if (lis == NULL){puts("Lista nula"); return NULL;}
    if (lis->qtde == 0){puts("Lista Vazia");return NULL;}
    
    
    Elemento *aux = lis->ultimo;
    if (lis->qtde == 1){
        lis->ultimo = NULL;
        lis->primeiro = NULL;
    } else{
        lis->ultimo = lis->ultimo->anterior;    // O penúltimo passa a ser o último da lista
        lis->ultimo->proximo = NULL;            // Desliga a lista do aux
        aux->anterior = NULL;                   // Desliga o aux da lista
    }
    
    lis->qtde--;
    
    return aux;
}


void pushPosiD(LinkedListD *lis, Elemento * el, int val){
  if(lis == NULL){puts("Lista nao existe");return;}
  if(el == NULL){puts("Elemento dado não existe"); return;}

  
  // Caso esteja vazia
  if(lis->qtde == 0){
    puts("Lista vazia! Elemento adicionado na primeira posicao");
    pushInicioD(lis, el);                                    // Adiciona no início
  } else {
    // Caso a posição não exista ainda
    if(val > lis -> qtde){
      puts("A lista nao possui esta posicao. Adicionando elemento no final");
      pushBackD(lis, el);
    } else {
      // Caso seja o primeiro elemento
      if(val == 0){
        pushInicioD(lis, el);
      } else {
        // Caso normal
        int i;
        Elemento * aux;
        for(i = 0, aux = lis -> primeiro; i != val; i++ ){    // Roda até a posição desejada 
            aux = aux -> proximo;                             // O aux recebe o sucessor
        }
        aux -> anterior -> proximo = el;                      // O anterior de aux aponta pro elemento
        el -> anterior = aux -> anterior;                     // Elemento tem o anterior ajustado  
        el -> proximo = aux;                                  // Elemento assume a posição
        aux -> anterior = el;
      }
    }
      
  }
  lis -> qtde++;
  return;
}


Elemento * popPosiD(LinkedListD *lis, int val){
    if(lis == NULL){puts("Lista nao existe");return NULL;}
    if(lis -> qtde == 0){puts("Lista vazia"); return NULL;}
    if(lis -> qtde < val){puts("Essa posicao nao existe nesta lista"); return NULL;}

    // Caso normal
    int i;
    Elemento * aux;
    // Caso só tenha um elemento na lista
    if(lis->qtde == 1){
        aux = lis->primeiro;
        lis -> primeiro = NULL;
        lis -> ultimo = NULL;
    } else{
        for(i = 0, aux = lis -> primeiro; i != val; i++){      // Roda até a posição desejada 
            aux = aux -> proximo;                              
        }
        aux -> anterior -> proximo = aux -> proximo;
        if(aux -> proximo != NULL){
            aux -> proximo -> anterior = aux -> anterior;      // Se n for nulo, o proximo de aux se liga ao anterior dele
        }
    }
    lis -> qtde--;
    aux -> proximo = NULL;
    aux -> anterior = NULL;

    return aux;
}



void listarD(LinkedListD * lis){
  if(lis == NULL){puts("Lista nao existe");return;}
  if(lis->qtde == 0){puts("Lista vazia");return;}

  Elemento * i;
  for (i = lis -> primeiro; i != NULL; i = i -> proximo){
    printf("%d - ", i-> valor);
  }
  printf("NULL\n");

}




#endif