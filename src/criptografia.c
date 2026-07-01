#include <ctype.h>
#include <string.h>

#include "criptografia.h"

static const char TABELA_HEX[] = "0123456789ABCDEF";

static void complementar_255(unsigned char *dados, size_t tamanho);

static void bytes_para_hex(const unsigned char *origem, size_t tamanho, char *destino);

static void hex_para_bytes(const char *origem, unsigned char *destino);

static int hex_para_valor(char c);

void criptografar_titulo(const char *titulo, char *titulo_criptografado)
{
    unsigned char buffer[MAX_TITULO];

    memcpy(buffer, titulo, MAX_TITULO);

    complementar_255(buffer, MAX_TITULO);

    bytes_para_hex(buffer, MAX_TITULO, titulo_criptografado);
}

void descriptografar_titulo(const char *titulo_criptografado, char *titulo)
{
    unsigned char buffer[MAX_TITULO];

    memset(buffer, 0, sizeof(buffer));

    hex_para_bytes(titulo_criptografado, buffer);

    complementar_255(buffer, MAX_TITULO);

    memcpy(titulo, buffer, MAX_TITULO);

    titulo[MAX_TITULO - 1] = '\0';
}

static void complementar_255(unsigned char *dados, size_t tamanho)
{
    size_t i;

    for (i = 0; i < tamanho; i++)
    {
        dados[i] = (unsigned char)(255 - dados[i]);
    }
}

static void bytes_para_hex(const unsigned char *origem, size_t tamanho, char *destino)
{
    size_t i;

    for (i = 0; i < tamanho; i++)
    {
        destino[2 * i] = TABELA_HEX[(origem[i] >> 4) & 0x0F];

        destino[2 * i + 1] = TABELA_HEX[origem[i] & 0x0F];
    }

    destino[2 * tamanho] = '\0';
}

static void hex_para_bytes(const char *origem, unsigned char *destino)
{
    size_t i = 0;

    while (origem[0] != '\0' && origem[1] != '\0')
    {
        destino[i++] = (unsigned char)((hex_para_valor(origem[0]) << 4) | hex_para_valor(origem[1]));

        origem += 2;
    }
}

static int hex_para_valor(char c)
{
    c = (char)toupper((unsigned char)c);

    if (c >= '0' && c <= '9') return c - '0';

    if (c >= 'A' && c <= 'F') return c - 'A' + 10;

    return 0;
}