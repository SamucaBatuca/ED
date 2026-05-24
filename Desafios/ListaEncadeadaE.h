#ifndef LISTAENCADEADAE_H
#define LISTAENCADEADAE_H

#include "ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct elementoE {
    Elemento * valor;          // O valor dele
    struct elementoE *proximo;   // Para onde ele vai apontar
} ElementoE;

typedef struct LinkedListE{
    ElementoE *primeiro;    // O topo da lista
    int qntd;               // A quantidade de elementos
}LinkedListE;


ElementoE * criaElementoE(Elemento * v){
  ElementoE * el = malloc(sizeof(ElementoE));  // Cria um espaço na memória no tamanho do elemento
  el -> valor = v;                           // Adiciona o valor dele
  el -> proximo = NULL;                      // Ele nativamente vai apontar para NULL, pois não está em uma lista
  return el;                                 // Retorna o elemento
}

LinkedListE * criaListaE(){
  LinkedListE * lis = malloc(sizeof(LinkedListE));    // Separa um espaço no tamanho de lista
  lis -> primeiro = NULL;                           // O primeiro elemento começa vazio
  lis -> qntd = 0;                                  // A quantidade começa zerada
  return lis;                                       // Retorna a lista
}


void pushInicioE(LinkedListE * lis, ElementoE * el){
  // Caso um dos parametros passados não exista
  if(lis == NULL || el == NULL){puts("Lista ou elemento não existem"); return;} 
  else{
    // Caso a lista esteja vazia
    if(lis -> qntd == 0){     
      lis -> primeiro = el;   // O novo elemento se torna o primeiro
      lis -> qntd++;          // Quantidade aumenta
    }
    // Caso já exista um elemento na lista
    else {
      el -> proximo = lis -> primeiro;  // O novo elemento aponta para o antigo primeiro
      lis -> primeiro = el;             // O primeiro da lista se torna o novo elemento
      lis -> qntd++;                    // Quantidade aumenta   
    }

  }

}


ElementoE * popInicioE(LinkedListE * lis){
  if(lis == NULL){puts("Lista nao existe");return NULL;}
  if(lis-> qntd == 0){puts("Lista vazia");return NULL;}

  ElementoE * aux = lis-> primeiro;    // pega o primeiro da lista
  lis -> primeiro = aux -> proximo;   // o primeiro da lista se torna oq antes era o segundo
  aux -> proximo = NULL;              // o antigo primeiro aponta pra NULL
  return aux;
}


void pushBackE(LinkedListE * lis, ElementoE * el){
  if(lis == NULL || el == NULL){puts("Lista ou elemento não existem"); return;} 
  else{
    // Caso a lista esteja vazia
    if(lis -> qntd == 0){     
      lis -> primeiro = el;   // O novo elemento se torna o primeiro
      lis -> qntd++;          // Quantidade aumenta
    } else {
      ElementoE * i;
      // Percorre até achar o ultimo elemento
      for (i = lis -> primeiro; i -> proximo != NULL ; i = i -> proximo);
      i -> proximo = el;   // O último elemento aponta pro elemento inserido
      lis -> qntd ++;      // Quantidade aumenta
    }
  }
}


ElementoE * popBackE(LinkedListE * lis){
  if(lis == NULL){puts("Lista nao existe");return NULL;}
  if(lis-> qntd == 0){puts("Lista vazia");return NULL;}
  
  ElementoE * aux = NULL, * i;
  // Se lista tiver só um elemento
  if(lis -> primeiro -> proximo == NULL){   // se o primeiro da lista apontar para um null, ele é o único elelemento nela
    aux = lis -> primeiro;
    lis -> primeiro = NULL;
  } else { // Lista tem mais de um elemento
    // Ele vai procurar o penúltimo da lista
    for (i = lis->primeiro; i -> proximo -> proximo != NULL ; i = i -> proximo);  // roda até o i ser o penúltimo
    aux = i-> proximo;      // auxiliar recebe o último
    i -> proximo = NULL;    // Define o penúltimo como último          
  }
  lis -> qntd--;
  return aux; 
}


void pushPosiE(LinkedListE *lis, ElementoE * el, int val){
  if(lis == NULL){puts("Lista nao existe");return;}
  if(el == NULL){puts("Elemento dado não existe"); return;}

  
  // Caso esteja vazia
  if(lis-> qntd == 0){
    puts("Lista vazia! Elemento adicionado na primeira posicao");
    pushInicioE(lis, el);                                    // Adiciona no início
  } else {
    // Caso a posição não exista ainda
    if(val > lis -> qntd){
      puts("A lista nao possui esta posicao. Adicionando elemento no final");
      pushBackE(lis, el);
    } else {
      // Caso seja o primeiro elemento
      if(val == 0){
        pushInicioE(lis, el);
      } else {
        // Caso normal
        int i;
        ElementoE * aux, * ant;
        for(i = 0, aux = lis -> primeiro; i != val; i++ ){    // Roda até a posição desejada 
          ant = aux;                                          // Salva uma posição anterior
          aux = aux -> proximo;                               // O aux recebe o sucessor
        }
        el -> proximo = aux;                                  // Elemento assume a posição
        ant -> proximo = el;                                  // Aux aponta pro elemento
      }
    }
      
  }
  lis -> qntd++;
  return;
}


ElementoE * popPosiE(LinkedListE *lis, int val){
  if(lis == NULL){puts("Lista nao existe");return NULL;}
  if(lis -> qntd == 0){puts("Lista vazia"); return NULL;}
  if(lis -> qntd < val){puts("Essa posicao nao existe nesta lista"); return NULL;}

  // Caso normal
  int i;
  ElementoE * aux, * el;
  for(i = 0, el = lis -> primeiro; i != val; i++){    // Roda até a posição desejada 
    aux = el;                                         // Aux salva o anterior
    el = el -> proximo;                               // O el recebe o sucessor
  }
  aux -> proximo = el -> proximo;
  el -> proximo = NULL;
  return el;
}


void listarE(LinkedListE * lis){
  if(lis == NULL){puts("Lista nao existe");return;}
  if(lis-> qntd == 0){puts("Lista vazia");return;}

  ElementoE * i;
  for (i = lis -> primeiro; i != NULL; i = i -> proximo){
    printf("%d - ", i-> valor);
  }
  printf("NULL\n");

}


#endif