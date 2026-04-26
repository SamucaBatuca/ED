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


Elemento * popInicio(LinkedList * lis){
  if(lis == NULL){puts("Lista nao existe");return NULL;}
  if(lis-> qntd == 0){puts("Lista vazia");return NULL;}

  Elemento * aux = lis-> primeiro;    // pega o primeiro da lista
  lis -> primeiro = aux -> proximo;   // o primeiro da lista se torna oq antes era o segundo
  aux -> proximo = NULL;              // o antigo primeiro aponta pra NULL
  return aux;
}


void pushBack(LinkedList * lis, Elemento * el){
  if(lis == NULL || el == NULL){puts("Lista ou elemento não existem"); return;} 
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
  if(lis == NULL){puts("Lista nao existe");return NULL;}
  if(lis-> qntd == 0){puts("Lista vazia");return NULL;}
  
  Elemento * aux = NULL, * i;
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


void listar(LinkedList * lis){
  if(lis == NULL){puts("Lista nao existe");return;}
  if(lis-> qntd == 0){puts("Lista vazia");return;}

  Elemento * i;
  for (i = lis -> primeiro; i != NULL; i = i -> proximo){
    printf("%d - ", i-> valor);
  }
  printf("NULL\n");

}





int menu();

int main()
{
    int op = menu(), val;
    Elemento *novo;
    LinkedList *l = criaLista();
    while (op != 0)
    {
        switch (op)
        {
        case 1:
            puts("Digite o valor a ser inserido: ");
            scanf("%d", &val);
            novo = criaElemento(val);
            pushInicio(l, novo);
            novo = NULL;
            break;

        case 2:
            novo = popInicio(l);
            printf("popado: %d\n", novo -> valor);
            novo = NULL;
            break;
        case 3:
            puts("Digite o valor a ser inserido: ");
            scanf("%d", &val);
            novo = criaElemento(val);
            pushBack(l, novo);
            novo = NULL;
            break;
        case 4:
            novo = popBack(l);
            printf("popado: %d\n", novo -> valor);
            break;
        case 5:
            listar(l);
            break;
        }
        op = menu();
    }
    return 0;
}

int menu()
{
    puts("1 - Inserir");
    puts("2 - tirar inicio");
    puts("3 - Inserir Fim");
    puts("4 - Tirar Fim");
    puts("5 - Listar");
    puts("0 - Sair");
    puts("Digite a opcao: ");
    int op;
    scanf("%d", &op);
    return op;
}

