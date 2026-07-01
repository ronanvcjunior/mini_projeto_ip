#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"
#include "lista.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    LivroMagicoNode *biblioteca;

    if (argc != 2)
    {
        fprintf(stderr, "Use: %s <arquivo.csv>\n", argv[0]);

        return EXIT_FAILURE;
    }

    lista_inicializar(&biblioteca);

    if (!arquivo_carregar(&biblioteca, argv[1]))
    {
        fprintf(stderr, "Erro ao carregar o arquivo.\n");

        lista_destruir(&biblioteca);

        return EXIT_FAILURE;
    }

    menu_executar(&biblioteca, argv[1]);

    if (!arquivo_salvar(biblioteca, argv[1]))
    {
        fprintf(stderr, "Erro ao salvar o arquivo.\n");
    }

    lista_destruir(&biblioteca);

    return EXIT_SUCCESS;
}