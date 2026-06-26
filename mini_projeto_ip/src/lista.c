#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/lista.h"

void init(LISTA *lista, char *nome_arquivo)
{
    *lista = NULL;

    carregar_estrutura(lista, nome_arquivo);
}

static void carregar_estrutura(LISTA *lista, char *nome_arquivo)
{
    FILE *fin;
    abrir_arquivo(&fin, nome_arquivo, "rb");

    LIVRO_MAGICO tmp; 
    LISTA *atual = lista;
    
    while (fread(&tmp, sizeof(LIVRO_MAGICO), 1, fin) == 1)
    {
        LISTA novo = malloc(sizeof(LIVRO_MAGICO));
        
        *novo = tmp;
        novo->prox = NULL;
        
        *atual = novo;
        atual = &((*atual)->prox);
    }
}

void salvar_estrutura(const LISTA *lista, char *nome_arquivo)
{
    FILE *fout;
    abrir_arquivo(&fout, nome_arquivo, "wb");

    LISTA atual = *lista;

    while (atual != NULL)
    {
        fwrite(atual, sizeof(LIVRO_MAGICO), 1, fout);
        atual = atual->prox;
    }

    fclose(fout);
}

static void abrir_arquivo(FILE **fp, const char *nome_arquivo, const char *opcao)
{
    *fp = fopen(nome_arquivo, opcao);

    if (*fp == NULL)
    {
        fprintf(stderr, "Erro: falha ao abrir o arquivo %s\n", nome_arquivo);
        exit(EXIT_FAILURE);
    }
}

void adicionar(LISTA * lista, const int id, const char *titulo)
{
    if (*lista == NULL)
    {
        LISTA novo = malloc(sizeof(LIVRO_MAGICO));
        strcpy(novo->titulo, titulo);
        novo->id = id;
        novo->prox = NULL;

        *lista = novo;
    }
    else
    {
        adicionar(&((*lista)->prox), id, titulo);
    }
}

void listar(const LISTA *lista)
{
    if (*lista != NULL)
    {
        printf("ID: %d, Titulo: %s\n", (*lista)->id, (*lista)->titulo);   
        listar(&((*lista)->prox));
    }
}