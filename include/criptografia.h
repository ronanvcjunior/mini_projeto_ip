#ifndef _CRIPTOGRAFIA_H_
#define _CRIPTOGRAFIA_H_

#include "constantes.h"

void criptografar_titulo(const char *titulo, char *titulo_criptografado);

void descriptografar_titulo(const char *titulo_criptografado, char *titulo);

#endif