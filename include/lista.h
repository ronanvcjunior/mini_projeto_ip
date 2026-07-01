#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdbool.h>

#include "livro.h"

typedef struct sLivroMagicoNode
{
    LivroMagico livro;
    struct sLivroMagicoNode *prox;
} LivroMagicoNode;

void lista_inicializar(LivroMagicoNode **lista);

void lista_destruir(LivroMagicoNode **lista);

bool lista_inserir(LivroMagicoNode **lista, const LivroMagico *livro);

LivroMagico *lista_buscar(LivroMagicoNode *lista, int id);

bool lista_remover(LivroMagicoNode **lista, int id);

bool lista_existe(LivroMagicoNode *lista, int id);

int lista_quantidade(LivroMagicoNode *lista);

bool lista_vazia(LivroMagicoNode *lista);

#endif