#include <stdio.h>
#include <string.h>

#define ARQUIVO "teste.dat"

#include "../include/lista.h"

int main()
{
    char nome_arquivo[100] = "./data/";
    strcat(nome_arquivo, ARQUIVO);
    LISTA registros;
    init(&registros, nome_arquivo);

    adicionar(&registros, 1, "Notredame");

    adicionar(&registros, 2, "O Auto da Compadecida");

    adicionar(&registros, 3, "Guerra & Paz");

    listar(&registros);

    salvar_estrutura(&registros, nome_arquivo);

    return 0;
}