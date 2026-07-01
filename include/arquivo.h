#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

#include <stdbool.h>

#include "lista.h"

bool arquivo_salvar(LivroMagicoNode *lista, const char *nome_arquivo);

bool arquivo_carregar(LivroMagicoNode **lista, const char *nome_arquivo);

#endif