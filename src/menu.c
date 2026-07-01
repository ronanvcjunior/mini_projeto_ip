#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "arquivo.h"
#include "constantes.h"
#include "util.h"

static int menu_ler_opcao(void);

static void menu_cadastrar(LivroMagicoNode **biblioteca);

static void menu_remover(LivroMagicoNode **biblioteca);

static void menu_mostrar(LivroMagicoNode *biblioteca);

static void menu_editar(LivroMagicoNode *biblioteca);

static void menu_listar(LivroMagicoNode *biblioteca);

void menu_executar( LivroMagicoNode **biblioteca, const char *nome_arquivo)
{
    int opcao;

    do
    {
        util_limpar_tela();

        opcao = menu_ler_opcao();

        switch (opcao)
        {
            case 1:
                menu_cadastrar(biblioteca);
                break;

            case 2:
                menu_remover(biblioteca);
                break;

            case 3:
                menu_mostrar(*biblioteca);
                break;

            case 4:
                menu_editar(*biblioteca);
                break;

            case 5:
                menu_listar(*biblioteca);
                break;

            case 6:

                if (arquivo_salvar(*biblioteca, nome_arquivo))
                {
                    printf("\nBiblioteca salva com sucesso.\n");
                }
                else
                {
                    printf("\nErro ao salvar a biblioteca.\n");
                }

                break;

            default:
                printf("\nOpcao invalida.\n");
        }

        if (opcao != 6)
        {
            util_pausar();
        }

    } while (opcao != 6);
}

static int menu_ler_opcao(void)
{
    int opcao;

    printf("=========================================\n");
    printf("        BIBLIOTECA MAGICA\n");
    printf("=========================================\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Remover livro\n");
    printf("3 - Mostrar livro\n");
    printf("4 - Editar livro\n");
    printf("5 - Listar titulos\n");
    printf("6 - Sair\n");
    printf("=========================================\n");
    printf("Opcao: ");

    scanf("%d", &opcao);
    util_limpar_buffer();

    return opcao;
}

static void menu_cadastrar(LivroMagicoNode **biblioteca)
{
    LivroMagico livro;

    printf("\n========== CADASTRO ==========\n");

    printf("ID: ");
    scanf("%d", &livro.id);
    util_limpar_buffer();

    if (lista_existe(*biblioteca, livro.id))
    {
        printf("\nJa existe um livro com esse ID.\n");
        return;
    }

    printf("Titulo: ");
    util_ler_string(livro.titulo, MAX_TITULO);

    if (util_contem_virgula(livro.titulo))
    {
        printf("\nO titulo não pode conter ','\n");
        return;
    }

    printf("Autor: ");
    util_ler_string(livro.autor.nome, MAX_NOME_AUTOR);

    if (util_contem_virgula(livro.autor.nome))
    {
        printf("\nO nome do autor não pode conter ','\n");
        return;
    }

    printf("\nData de nascimento do autor\n");

    printf("Dia: ");
    scanf("%d", &livro.autor.data_nascimento.dia);
    util_limpar_buffer();

    printf("Mes: ");
    scanf("%d", &livro.autor.data_nascimento.mes);
    util_limpar_buffer();

    printf("Ano: ");
    scanf("%d", &livro.autor.data_nascimento.ano);
    util_limpar_buffer();

    printf("\nData de escrita\n");

    printf("Dia: ");
    scanf("%d", &livro.data_escrita.dia);
    util_limpar_buffer();

    printf("Mes: ");
    scanf("%d", &livro.data_escrita.mes);
    util_limpar_buffer();

    printf("Ano: ");
    scanf("%d", &livro.data_escrita.ano);
    util_limpar_buffer();

    if (lista_inserir(biblioteca, &livro))
    {
        printf("\nLivro cadastrado com sucesso!\n");
    }
    else
    {
        printf("\nErro ao cadastrar livro.\n");
    }
}

static void menu_remover(LivroMagicoNode **biblioteca)
{
    int id;

    if (lista_vazia(*biblioteca))
    {
        printf("\nA biblioteca esta vazia.\n");
        return;
    }

    printf("\n========== REMOVER LIVRO ==========\n");

    printf("ID do livro: ");
    scanf("%d", &id);
    util_limpar_buffer();

    if (lista_remover(biblioteca, id))
    {
        printf("\nLivro removido com sucesso!\n");
    }
    else
    {
        printf("\nLivro nao encontrado.\n");
    }
}


static void menu_mostrar(LivroMagicoNode *biblioteca)
{
    int id;

    if (lista_vazia(biblioteca))
    {
        printf("\nA biblioteca esta vazia.\n");
        return;
    }

    printf("\n========== MOSTRAR LIVRO ==========\n");

    printf("ID do livro: ");
    scanf("%d", &id);
    util_limpar_buffer();

    LivroMagico *livro = lista_buscar(biblioteca, id);

    if (livro == NULL)
    {
        printf("\nLivro nao encontrado.\n");
        return;
    }

    printf("\n========== DADOS DO LIVRO ==========\n");

    printf("ID: %d\n", livro->id);

    printf("Titulo: %s\n", livro->titulo);

    printf("Autor: %s\n", livro->autor.nome);

    printf(
        "Nascimento do autor: %02d/%02d/%04d\n",
        livro->autor.data_nascimento.dia,
        livro->autor.data_nascimento.mes,
        livro->autor.data_nascimento.ano
    );

    printf(
        "Data de escrita: %02d/%02d/%04d\n",
        livro->data_escrita.dia,
        livro->data_escrita.mes,
        livro->data_escrita.ano
    );
}

static void menu_editar(LivroMagicoNode *biblioteca)
{
    int id;

    if (lista_vazia(biblioteca))
    {
        printf("\nA biblioteca esta vazia.\n");
        return;
    }

    printf("\n========== EDITAR LIVRO ==========\n");

    printf("ID do livro: ");
    scanf("%d", &id);
    util_limpar_buffer();

    LivroMagico *livro = lista_buscar(biblioteca, id);

    if (livro == NULL)
    {
        printf("\nLivro nao encontrado.\n");
        return;
    }

    printf("\nNovo titulo: ");
    util_ler_string(livro->titulo, MAX_TITULO);

    printf("Novo autor: ");
    util_ler_string(livro->autor.nome, MAX_NOME_AUTOR);

    printf("\nNova data de nascimento do autor\n");

    printf("Dia: ");
    scanf("%d", &livro->autor.data_nascimento.dia);
    util_limpar_buffer();

    printf("Mes: ");
    scanf("%d", &livro->autor.data_nascimento.mes);
    util_limpar_buffer();

    printf("Ano: ");
    scanf("%d", &livro->autor.data_nascimento.ano);
    util_limpar_buffer();

    printf("\nNova data de escrita\n");

    printf("Dia: ");
    scanf("%d", &livro->data_escrita.dia);
    util_limpar_buffer();

    printf("Mes: ");
    scanf("%d", &livro->data_escrita.mes);
    util_limpar_buffer();

    printf("Ano: ");
    scanf("%d", &livro->data_escrita.ano);
    util_limpar_buffer();

    printf("\nLivro atualizado com sucesso!\n");
}

static void menu_listar(LivroMagicoNode *biblioteca)
{
    if (lista_vazia(biblioteca))
    {
        printf("\nA biblioteca esta vazia.\n");
        return;
    }

    printf("\n========== LIVROS CADASTRADOS ==========\n\n");

    LivroMagicoNode *atual = biblioteca;

    while (atual != NULL)
    {
        printf(
            "ID: %-5d Titulo: %s\n",
            atual->livro.id,
            atual->livro.titulo
        );

        atual = atual->prox;
    }

    printf("\nTotal de livros: %d\n", lista_quantidade(biblioteca));
}