#include <stdbool.h>
#include <stdlib.h>

#include "lista.h"

void lista_inicializar(LivroMagicoNode **lista)
{
    *lista = NULL;
}

void lista_destruir(LivroMagicoNode **lista)
{
    LivroMagicoNode *atual = *lista;

    while (atual != NULL)
    {
        LivroMagicoNode *proximo = atual->prox;

        free(atual);

        atual = proximo;
    }

    *lista = NULL;
}

bool lista_inserir(LivroMagicoNode **lista, const LivroMagico *livro)
{
    LivroMagicoNode *novo = malloc(sizeof(LivroMagicoNode));

    if (novo == NULL) return false;

    novo->livro = *livro;
    novo->prox = NULL;

    if (*lista == NULL)
    {
        *lista = novo;
        return true;
    }

    LivroMagicoNode *atual = *lista;

    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    atual->prox = novo;

    return true;
}

LivroMagico *lista_buscar(LivroMagicoNode *lista, int id)
{
    while (lista != NULL)
    {
        if (lista->livro.id == id) return &(lista->livro);

        lista = lista->prox;
    }

    return NULL;
}

bool lista_remover(LivroMagicoNode **lista, int id)
{
    LivroMagicoNode *atual = *lista;
    LivroMagicoNode *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->livro.id == id)
        {
            if (anterior == NULL)
            {
                *lista = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            free(atual);

            return true;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return false;
}

bool lista_existe(LivroMagicoNode *lista, int id)
{
    return lista_buscar(lista, id) != NULL;
}

int lista_quantidade(LivroMagicoNode *lista)
{
    int quantidade = 0;

    while (lista != NULL)
    {
        quantidade++;
        lista = lista->prox;
    }

    return quantidade;
}

bool lista_vazia(LivroMagicoNode *lista)
{
    return lista == NULL;
}