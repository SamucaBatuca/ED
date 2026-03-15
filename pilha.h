//Definição do tipo de abstrato de dados Pilha
typedef struct pilha{
    Tipo *p;
    int qtde;
    int topo;
    int tamanho;
}Pilha;
//Função para criação e iniciação de uma Pilha
Pilha* criaPilha(int tam){
    Pilha* pi = malloc(sizeof(Pilha));
    pi->p = malloc(sizeof(Tipo)*tam);
    pi->tamanho = tam;
    pi->qtde = 0;
    pi->topo = -1;
    return pi;
}
//Função para inserir (empilhar/LIFO) um elemento na Pilha
void push(Pilha* pi, Tipo e){
    if(pi==NULL){
        puts("Pilha Inexistente");
        return;
    }
    if(pi->qtde == pi->tamanho){
        puts("Pilha Cheia");
        return;
    }
    pi->qtde++;
    pi->topo++;
    *((pi->p)+pi->topo) = e;
    return;
}
//Função para retirar (desempilhar/LIFO) um elemento da Pilha
Tipo pop(Pilha* pi){
    Tipo e;
    if(pi != NULL ){
        if(pi->qtde!=0){
            pi->qtde--;
            e = *((pi->p)+pi->topo);
            pi->topo--;
        }
        else{
            puts("Pilha Vazia");
        }
    }
    else{
        puts("Pilha Inexistente");
    }
    return e;
}