#include <stdio.h>
#include <stdlib.h>

#define Tipo int

typedef struct Lista
{
    Tipo *l;
    int qtd;
    int front;
    int back;
    int tamanho;
} Lista;

Lista * criaLista(int tam){ // retorna um poteiro do tipo Lista
    Lista *li = malloc(sizeof(Lista)); // cria o ponteiro da Lista
    li -> tamanho = tam; // define o tamanho
    li -> qtd = 0; // zera
    li -> front = 0; // define onde começa (inicialmente na posição zero)
    li -> back = -1; // define o final (como ta vazio inicialmente, então é -1)
    li -> l = malloc(sizeof(Tipo)*tam); // cria os espaços para armazenar na Lista
}

void pushFront (Lista *li, Tipo val){
    if (li!= NULL){ // ve se a Fila existe
        if (li -> tamanho == li -> qtd){ // se o tamanho da lista não estourou
            puts ("Lista cheia");
            return;
        }
        li -> back++; // o fim da lista anda
        *((li->l)+ li -> back) = val;
        /* Isso significa: aponte para o ponteiro do slot de variáveis da
            Fila somado ao fim (ou seja, aponta pro fim) e insira nele
            uma variável do tipo anteriormente definido 
        */
        li -> qtd++; // adiciona mais um à quantidade
    }
    return;
}


void pushBack(Lista *li, Tipo val){
    if (li!= NULL){ // ve se a lista existe
        if (li -> tamanho == li -> qtd){ // se o tamanho da lista não estourou
            puts ("Lista cheia");
            return;
        }
        li -> back++; // o fim da lista anda
        *((li->l)+ li -> back) = val;
        /* Isso significa: aponte para o ponteiro do slot de variáveis da
            Fila somado ao fim (ou seja, aponta pro fim) e insira nele
            uma variável do tipo anteriormente definido 
        */
        li -> qtd++; // adiciona mais um à quantidade
    }
    return;
}


void pushPosicao(Lista *li, int posi, Tipo val){
    if (li!= NULL){ // ve se a lista existe
        if (li -> tamanho == li -> qtd){ // se o tamanho da Lista não estourou
            puts ("Lista cheia");
            return;
        }
        Tipo cont = 0;
        Tipo aux;
        while((li->back-cont) > posi){ // enquanto não chega na posição
            cont++;
            aux = *((li->l) + li->back - cont);// pega valor da posição anterior a back
            *((li->l) + li->back - (cont-1))= aux; // insere a posição anterior no atual back
        }

        *(li->l+posi) = val; // atribuindo valor na posição
        
        li -> qtd++; // adiciona mais um à quantidade
    } else {
        puts("Essa Lista não existe");
    }
    return;
}

Tipo popFront(Lista* li){
    Tipo e; // informação a ser retornada
    if(li != NULL ){ // se existe a lista
        if(li->qtd!=0){ // se ela já não estiver vazia
            li->qtd--; // diminue a quantidade de elementos
            e = *((li->l)+li->front); // o retorno vai receber o começo da lista
            li->front++;
        }
        else{
            puts("Lista vazia"); // se estiver vazia, retorna isso
        }
    }
    else{
        puts("Essa Lista não existe"); // se não existir fila
    }
    return e; // retorna a informação que será popada
}


Tipo popBack(Lista* li){
    Tipo e; // informação a ser retornada
    if(li != NULL ){ // se existe a lista
        if(li->qtd!=0){ // se ela já não estiver vazia
            li->qtd--; // diminue a quantidade de elementos
            e = *((li->l)+li->back); // o retorno vai receber o fim da Lista
            li->back--;
        }
        else{
            puts("Lista vazia"); // se estiver vazia, retorna isso
        }
    }
    else{
        puts("Essa lista não existe"); // se não existir Lista
    }
    return e; // retorna a informação que será popada
}


Tipo popPosicao(Lista* li, int posi){
    Tipo e; // informação a ser retornada
    if(li != NULL ){ // se existe a lista
        if(li->qtd!=0){ // se ela já não estiver vazia
            e = *((li->l)+posi); // o retorno vai receber a informação na posição
            int cont = posi;
            Tipo aux;
            while((li->l+cont) < (li->l + li->back)){ // enquanto não chega no back
                cont++;
                aux = *((li->l) + cont);// pega valor afrente da posição atual
                *((li->l) + cont-1)= aux; // insere na posição atual
            }
            li->back--; // ddiminui o referencial do back
            li->qtd--; // diminue a quantidade de elementos
        }else{
            puts("Lista vazia"); // se estiver vazia, retorna isso
        }
    }
    else{
        puts("Essa lista não existe"); // se não existir lista
    }
    return e; // retorna a informação que será popada

}


int main() {
    Tipo i;
    Lista *li = criaLista(4);

    pushBack(li,2);

    pushFront(li,1);

    while(li->qtd != 0){
        Tipo aux = popBack(li);
        printf("\n%d", aux);
    }

    return 0;
}
