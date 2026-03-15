#include <stdio.h>
#include <stdlib.h>

#define Tipo int



typedef struct Fila
{
    Tipo *f;
    int qtd;
    int ini;
    int fim;
    int tamanho;
} Fila;


Fila * criaFila(int tam){ // retorna um poteiro do tipo Fila
    Fila *fi = malloc(sizeof(Fila)); // cria o ponteiro da Fila
    fi -> tamanho = tam; // define o tamanho
    fi -> qtd = 0; // zera
    fi -> ini = 0; // define onde começa (inicialmente na posição zero)
    fi -> fim = -1; // define o final (como ta vazio inicialmente, então é -1)
    fi -> f = malloc(sizeof(Tipo)*tam); // cria os espaços para armazenar na Fila
}

void push (Fila *fi, Tipo val){
    int i;
    
    if (fi!= NULL){ // ve se a Fila existe
        if (fi -> tamanho == fi -> qtd){ // se o tamanho da Filha não estourou
            puts ("Fila cheia");
            return;
        }
        Tipo aux;

        if(fi->qtd == 0){ //para o primeiro a ser add
            fi->qtd++;
            *(fi->f) = val;
            fi-> fim++; // ajusta o back
        } else { // para os demais casos
            
            for(i = 0; *((fi->f)+ fi->fim-i) >= val && i < fi->tamanho; i++); // roda a fila até achar alguém menor ou igual
            //printf("--i: %d; tamanho: %d--\n", i, fi->qtd);

            if(i > fi->qtd){ // se não achar alguém menor doq ele, é pq ele É o menor
                Tipo cont = 0;
                fi-> fim++;
                while((fi->fim-cont) > fi->ini ){ // anda até o número encontrado
                    cont++;
                    aux = *((fi->f) + fi->fim - cont);// pega valor da posição anterior
                    *((fi->f) + fi->fim - (cont-1))= aux; // insere a posição anterior no atual
                }
                *(fi->f )= val; // insere o valor no lugar do ultimo valor maior que ela
                fi -> qtd++; // adiciona mais um à quantidade

            } else{ // caso exista alguém menor doq ele
                fi-> fim++; // ajusta o back
                Tipo cont = 0;
                while((fi->fim-cont) > fi->fim - i){ // anda até o número encontrado
                    cont++;
                    aux = *((fi->f) + fi->fim - cont);// pega valor da posição anterior
                    *((fi->f) + fi->fim - (cont-1))= aux; // insere a posição anterior no atual
                }
                *((fi->f) + fi->fim - i)= val; // insere o valor no lugar do ultimo valor maior que ela
                fi -> qtd++; // adiciona mais um à quantidade
            }
        }


            

        
    }
    return;
}


Tipo pop(Fila* fi){
    Tipo e; // informação a ser retornada
    if(fi != NULL ){ // se existe a fila
        if(fi->qtd!=0){ // se ela já não estiver vazia
            fi->qtd--; // diminue a quantidade de elementos
            e = *((fi->f)+fi->ini); // o retorno vai receber o começo da fila
            fi->ini++;
        }
        else{
            puts("Fila vazia"); // se estiver vazia, retorna isso
        }
    }
    else{
        puts("Essa fila não existe"); // se não existir fila
    }
    return e; // retorna a informação que será popada
}




int main() {
    Tipo i;
    Fila *fi = criaFila(10);

    push(fi,2);
    push(fi,4);
    push(fi,1);
    push(fi,3);
    push(fi,5);
    push(fi,10);
    push(fi,8);


    while(fi->qtd != 0){
        Tipo aux = pop(fi);
        printf("\n%d", aux);
    }

    return 0;
}
