#ifndef LikedListD_H
#define LikedListD_H

#include <stdlib.h>
#include <stdio.h>
typedef struct elemento
{
    int num;
    struct elemento *proximo;
    struct elemento *anterior;
} Elemento;

typedef struct listaDuplamenteLigada
{
    Elemento *primeiro;
    Elemento *ultimo;
    int qtde;
} ListaDuplamenteLigada;
// Primeiro da lista = Seu anterior = NULL
// Último da lista = Seu próximo = NULL

Elemento *criarElemento(int n)
{
    Elemento *e = (Elemento *)malloc(sizeof(Elemento));
    e->num = n;
    e->proximo = NULL;
    e->anterior = NULL;
    return e;
}

ListaDuplamenteLigada *criarListaDuplamenteLigada()
{
    ListaDuplamenteLigada *l = (ListaDuplamenteLigada *)malloc(sizeof(ListaDuplamenteLigada));
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->qtde = 0;
    return l;
}

void inserirInicio(ListaDuplamenteLigada *l, Elemento *novo)
{
    if (l == NULL || novo == NULL)
    {
        puts("Lista ou Elemento nulo(s)");
    }
    else
    {
        if (l->qtde == 0)
        { // Lista vazia
            l->primeiro = novo;
            l->ultimo = novo;
        }
        else
        {                                 // Lista com elemento
            novo->proximo = l->primeiro;  // ligamos novo à lista (primeiro)
            l->primeiro->anterior = novo; // ligamos o primeiro (lista) ao novo
            l->primeiro = novo;           // modificamos o primeiro (lista) para ser o novo
        }
        l->qtde++;
    }
}

Elemento *removerElementoInicio(ListaDuplamenteLigada *l)
{
    Elemento *aux = NULL;
    if (l == NULL)
    {
        puts("Lista Vazia");
    }
    else
    {
        aux = l->primeiro;
        if (l->qtde == 1)
        {
            l->primeiro = NULL;
            l->ultimo = NULL;
        }
        else
        {
            l->primeiro = l->primeiro->proximo; // Primeiro passa a ser o segundo
            l->primeiro->anterior = NULL;       // Deligo a lista do aux
            aux->proximo = NULL;                // Desligo o aux da lista
        }
        l->qtde--;
    }
    return aux;
}

void inserirNoFinal(ListaDuplamenteLigada *l, Elemento *novo)
{
    if (l == NULL || novo == NULL)
    {
        puts("Lista ou Elemento nulo(s)");
    }
    else
    {
        if (l->qtde == 0)
        {
            l->primeiro = novo;
            l->ultimo = novo;
        }
        else
        {
            l->ultimo->proximo = novo;  // Liga a lista no novo
            novo->anterior = l->ultimo; // Liga o novo na lista
            l->ultimo = novo;           // Altera o último da lista para o novo
        }
        l->qtde++;
    }
}

Elemento *retirarDoFinal(ListaDuplamenteLigada *l)
{
    Elemento *aux = NULL;
    if (l == NULL)
    {
        puts("Lista nula");
    }
    else
    {
        if (l->qtde == 0)
        {
            puts("Lista Vazia");
        }
        else
        {
            aux = l->ultimo;
            if (l->qtde == 1)
            {
                l->ultimo = NULL;
                l->primeiro = NULL;
            }
            else
            {
                l->ultimo = l->ultimo->anterior; // O penúltimo passa a ser o último da lista
                l->ultimo->proximo = NULL;       // Desliga a lista do aux
                aux->anterior = NULL;            // Desliga o aux da lista
            }
            l->qtde--;
        }
    }
    return aux;
}
#endif