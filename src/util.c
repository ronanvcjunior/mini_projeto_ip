#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

void util_limpar_buffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

void util_ler_string(char *texto, size_t tamanho)
{
    if (texto == NULL || tamanho == 0)
        return;

    if (fgets(texto, (int)tamanho, stdin) == NULL)
    {
        texto[0] = '\0';
        return;
    }

    texto[strcspn(texto, "\n")] = '\0';
}

bool util_contem_virgula(const char *texto)
{
    while (*texto != '\0')
    {
        if (*texto == ',')
        {
            return true;
        }

        texto++;
    }

    return false;
}

void util_limpar_tela(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void util_pausar(void)
{
    printf("\nPressione ENTER para continuar...");

    fflush(stdout);

    util_limpar_buffer();
}