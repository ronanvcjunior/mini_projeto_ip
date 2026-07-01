#ifndef _LIVRO_H_
#define _LIVRO_H_

#include "constantes.h"

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char nome[MAX_NOME_AUTOR];
    Data data_nascimento;
} Autor;

typedef struct
{
    int id;
    char titulo[MAX_TITULO];
    Autor autor;
    Data data_escrita;
} LivroMagico;

#endif