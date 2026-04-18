#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;                 // O valor dele
    struct elemento *proximo;  // Para onde ele vai apontar
} Elemento;

typedef struct LinkedList{
    Elemento *primeiro;   // O topo da lista
    int qntd;             // A quantidade de elementos
}LinkedList;


Elemento * criaElemento(int v){
  Elemento * el = malloc(sizeof(Elemento));  // Cria um espaço na memória no tamanho do elemento
  el -> valor = v;                           // Adiciona o valor dele
  el -> proximo = NULL;                      // Ele nativamente vai apontar para NULL, pois não está em uma lista
  return el;                                 // Retorna o elemento
}

LinkedList * criaLista(){
  LinkedList * lis = malloc(sizeof(LinkedList));    // Separa um espaço no tamanho de lista
  lis -> primeiro = NULL;                           // O primeiro elemento começa vazio
  lis -> qntd = 0;                                  // A quantidade começa zerada
  return lis;                                       // Retorna a lista
}


void pushInicio(LinkedList * lis, Elemento * el){
  // Caso um dos parametros passados não exista
  if(lis == NULL || el == NULL){puts("Lista ou elemento não existem");} 
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


Elemento * popInicio(LinkedList * lis){
  if(lis == NULL){puts("Lista nao existe");return;}
  if(lis-> qntd == 0){puts("Lista vazia");return;}

  Elemento * aux = lis-> primeiro;    // pega o primeiro da lista
  lis -> primeiro = aux -> proximo;   // o primeiro da lista se torna oq antes era o segundo
  aux -> proximo = NULL;              // o antigo primeiro aponta pra NULL
  return aux;
}


void pushBack(LinkedList * lis, Elemento * el){
  if(lis == NULL || el == NULL){puts("Lista ou elemento não existem");} 
  else{
    // Caso a lista esteja vazia
    if(lis -> qntd == 0){     
      lis -> primeiro = el;   // O novo elemento se torna o primeiro
      lis -> qntd++;          // Quantidade aumenta
    } else {
      Elemento * i;
      // Percorre até achar o ultimo elemento
      for (i = lis -> primeiro; i -> proximo != NULL ; i = i -> proximo);
      i -> proximo = el;   // O último elemento aponta pro elemento inserido
      lis -> qntd ++;      // Quantidade aumenta
    }
  }
}


Elemento * popBack(LinkedList * lis){
  if(lis == NULL){puts("Lista nao existe");return;}
  if(lis-> qntd == 0){puts("Lista vazia");return NULL;}
  
  Elemento * aux, * i;
  // Se lista tiver só um elemento
  if(lis -> qntd == 1){
    aux = lis -> primeiro;
    lis -> qntd--;
    return aux;
  } else { // Lista tem mais de um elemento
    // Ele vai procurar o penúltimo da lista
    for (i = lis -> primeiro, aux = i -> proximo; aux -> proximo != NULL ; i = i -> proximo, aux = i -> proximo);
    i -> proximo == NULL;   // Define o penúltimo como último
    return aux;             // Retorna o antigo último
  }

}


void listar(LinkedList * lis){
  if(lis == NULL){puts("Lista nao existe");return;}
  if(lis-> qntd == 0){puts("Lista vazia");return;}

  Elemento * i;
  for (i = lis -> primeiro; i != NULL; i = i -> proximo){
    printf("%d - ", i-> valor);
  }
  printf("NULL\n");

}






int main(){


}