#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

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