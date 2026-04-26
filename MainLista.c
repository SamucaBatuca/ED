#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int menu();

int main()
{
    int op = menu(), val, posi;
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
            puts("Digite o valor a ser inserido: ");
            scanf("%d", &val);
            novo = criaElemento(val);
            puts("Digite a posicao a ser inserido (considere 0 como a primeira posicao): ");
            scanf("%d", &posi);
            pushPosi(l,novo,posi);
            puts("Valor inserido com sucesso!");
            novo = NULL;
            break;
        case 6:
            puts("Digite a posicao que deseja remover: ");
            scanf("%d", &posi);
            novo = popPosi(l,posi);
            if(novo == NULL){puts("Nenhum valor foi removido");}
            else{printf("O valor removido foi: %d\n", novo -> valor);}
            break;
        case 7:
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
    puts("5 - Inserir Posicao");
    puts("6 - Remover Posicao");
    puts("7 - Listar");
    puts("0 - Sair");
    puts("Digite a opcao: ");
    int op;
    scanf("%d", &op);
    return op;
}