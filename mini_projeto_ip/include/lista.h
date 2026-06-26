#ifndef _LISTA_H_
#define _LISTA_H_

#define MAX_SIZE 100

typedef struct
{
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct
{
    char nome[MAX_SIZE];
    DATA data_nascimento;
} AUTOR;

typedef struct sLIVRO_MAGICO
{
    int id;
    char titulo[MAX_SIZE];
    // AUTOR autor;
    // DATA data_escrita;
    struct sLIVRO_MAGICO *prox;
} LIVRO_MAGICO;

typedef LIVRO_MAGICO * LISTA;

void init(LISTA * lista, char *nome_arquivo);
static void carregar_estrutura(LISTA * lista, char *nome_arquivo);
void salvar_estrutura(const LISTA * lista, char *nome_arquivo);

static void abrir_arquivo(FILE **fp, const char *nome_arquivo, const char *opcao);

void adicionar(LISTA * lista, const int id, const char *titulo);
void listar(const LISTA * lista);

#endif