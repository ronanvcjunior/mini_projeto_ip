#include <stdbool.h>
#include <stdio.h>

#include "arquivo.h"
#include "criptografia.h"

static FILE *arquivo_abrir(const char *nome, const char *modo);

static void arquivo_pular_cabecalho(FILE *arquivo);

bool arquivo_salvar(LivroMagicoNode *lista, const char *nome_arquivo)
{
    FILE *arquivo = arquivo_abrir(nome_arquivo, "w");

    if (arquivo == NULL) return false;

    fprintf(
        arquivo,
        "ID,Titulo,Autor,DiaNascimento,MesNascimento,AnoNascimento,"
        "DiaEscrita,MesEscrita,AnoEscrita\n"
    );

    while (lista != NULL)
    {
        char titulo[MAX_TITULO_CRIPTOGRAFADO];

        criptografar_titulo( lista->livro.titulo, titulo);

        fprintf(
            arquivo,
            "%d,%s,%s,%d,%d,%d,%d,%d,%d\n",
            lista->livro.id,
            titulo,
            lista->livro.autor.nome,
            lista->livro.autor.data_nascimento.dia,
            lista->livro.autor.data_nascimento.mes,
            lista->livro.autor.data_nascimento.ano,
            lista->livro.data_escrita.dia,
            lista->livro.data_escrita.mes,
            lista->livro.data_escrita.ano
        );

        lista = lista->prox;
    }

    fclose(arquivo);

    return true;
}

bool arquivo_carregar(LivroMagicoNode **lista, const char *nome_arquivo)
{
    FILE *arquivo = arquivo_abrir(nome_arquivo, "r");

    if (arquivo == NULL) return true;

    arquivo_pular_cabecalho(arquivo);

    LivroMagico livro;
    char titulo[MAX_TITULO_CRIPTOGRAFADO];

    while (
        fscanf(
            arquivo,
            "%d,%200[^,],%99[^,],%d,%d,%d,%d,%d,%d\n",
            &livro.id,
            titulo,
            livro.autor.nome,
            &livro.autor.data_nascimento.dia,
            &livro.autor.data_nascimento.mes,
            &livro.autor.data_nascimento.ano,
            &livro.data_escrita.dia,
            &livro.data_escrita.mes,
            &livro.data_escrita.ano
        ) == 9
    )
    {
        descriptografar_titulo(titulo, livro.titulo);

        if (!lista_inserir(lista, &livro))
        {
            fclose(arquivo);
            return false;
        }
    }

    fclose(arquivo);

    return true;
}

static FILE *arquivo_abrir(const char *nome, const char *modo)
{
    return fopen(nome, modo);
}

static void arquivo_pular_cabecalho(FILE *arquivo)
{
    char linha[256];

    fgets(linha, sizeof(linha), arquivo);
}