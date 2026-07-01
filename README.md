# Biblioteca Mágica

## Descrição

Biblioteca Mágica é um sistema desenvolvido em linguagem **C11** que simula o backend do inventário de livros mágicos de um jogo de RPG.

O programa permite cadastrar, consultar, editar, remover e listar livros, mantendo todas as informações persistidas em um arquivo CSV.

Como especificado no enunciado do projeto, o campo **Título** é criptografado antes de ser salvo em disco e descriptografado automaticamente durante o carregamento.

O sistema foi desenvolvido de forma modular, utilizando conceitos fundamentais de Programação em C, Estruturas de Dados e Engenharia de Software.

---

# Funcionalidades

O sistema implementa as seguintes funcionalidades:

* Cadastro de livros.
* Remoção de livros pelo identificador.
* Consulta completa de um livro.
* Edição dos dados de um livro.
* Listagem de todos os livros cadastrados.
* Salvamento automático em arquivo CSV.
* Carregamento automático ao iniciar o programa.
* Criptografia do título dos livros.
* Descriptografia automática durante a leitura.
* Alocação dinâmica utilizando lista encadeada.

---

# Tecnologias Utilizadas

* Linguagem C
* Padrão C11
* GCC
* CMake
* Make
* Git
* GitHub
* Visual Studio Code

---

# Bibliotecas Utilizadas

Bibliotecas padrão da linguagem C:

* stdio.h
* stdlib.h
* string.h
* stdbool.h
* ctype.h

---

# Estrutura do Projeto

```text
BibliotecaMagica/
│
├── CMakeLists.txt
├── README.md
│
├── include/
│   ├── arquivo.h
│   ├── constantes.h
│   ├── criptografia.h
│   ├── livro.h
│   ├── lista.h
│   ├── menu.h
│   └── util.h
│
├── src/
│   ├── arquivo.c
│   ├── criptografia.c
│   ├── lista.c
│   ├── main.c
│   ├── menu.c
│   └── util.c
│
├── data/
│   └── biblioteca.csv
│
└── build/
```

---

# Arquitetura

O projeto foi dividido em módulos independentes.

## livro

Define todas as estruturas utilizadas pelo sistema.

* Data
* Autor
* LivroMagico

---

## lista

Implementa a lista encadeada responsável pelo armazenamento dos livros em memória.

Operações implementadas:

* Inserção
* Remoção
* Busca
* Contagem
* Listagem
* Liberação de memória

---

## arquivo

Responsável pelo salvamento e carregamento dos dados.

Utiliza arquivos CSV para armazenamento permanente.

---

## criptografia

Implementa toda a lógica de criptografia do campo **Título**.

Todo o algoritmo permanece encapsulado neste módulo.

---

## util

Funções auxiliares utilizadas pelo sistema.

Exemplos:

* leitura de strings
* leitura de números
* limpeza da tela
* pausa da execução
* validações

---

## menu

Responsável pela interação com o usuário.

---

# Estruturas Utilizadas

## Data

* dia
* mês
* ano

## Autor

* nome
* data de nascimento

## LivroMagico

* ID
* título
* autor
* data de escrita

## Lista Encadeada

Cada livro é armazenado dinamicamente em um nó da lista.

---

# Persistência dos Dados

Todos os livros são armazenados em um arquivo CSV.

O título é criptografado antes da gravação.

Ao iniciar o programa:

* o arquivo é aberto;
* todos os registros são carregados;
* os títulos são descriptografados;
* os livros são inseridos na lista encadeada.

Ao encerrar:

* o arquivo é recriado;
* todos os livros são gravados novamente.

---

# Formato do Arquivo

Os dados são armazenados em formato CSV.

A primeira linha contém o cabeçalho.

Exemplo:

```csv
ID,Titulo,Autor,DiaNascimento,MesNascimento,AnoNascimento,DiaEscrita,MesEscrita,AnoEscrita
1,AEF2...,J. R. R. Tolkien,3,1,1892,29,7,1954
```

O campo **Título** encontra-se criptografado.

Todos os demais campos permanecem em texto.

---

# Criptografia

O algoritmo utilizado segue exatamente o especificado no enunciado.

Para cada byte do título é aplicado:

novo_byte = 255 - byte_original

Após a criptografia, os bytes são convertidos para hexadecimal antes da gravação no arquivo CSV.

Durante o carregamento:

1. O hexadecimal é convertido novamente para bytes.
2. O complemento de 255 é aplicado novamente.
3. O título original é restaurado.

Como o complemento de 255 é sua própria inversa, o mesmo algoritmo é suficiente para criptografar e descriptografar.

---

# Funcionamento Geral

Ao iniciar o programa:

1. O arquivo CSV é aberto.
2. O cabeçalho é ignorado.
3. Todos os livros são carregados.
4. Os títulos são descriptografados.
5. Os livros são inseridos na lista encadeada.

Durante a execução:

- O usuário interage através do menu.
- Todas as alterações ocorrem apenas na memória.

Ao encerrar:

1. O arquivo CSV é recriado.
2. O cabeçalho é escrito.
3. Cada livro é criptografado.
4. Todos os registros são gravados.
5. Toda a memória alocada dinamicamente é liberada.

---

# Como Compilar e Executar

## Pré-requisitos

É necessário possuir instalado:

* GCC com suporte ao padrão C11
* CMake 3.20 ou superior
* Make

Verifique a instalação:

```bash
gcc --version
cmake --version
make --version
```

---

## Compilação utilizando CMake

Na pasta raiz do projeto execute:

```bash
cmake -S . -B build
```

Depois:

```bash
cmake --build build
```

---

## Compilação manual

Caso deseje compilar manualmente:

```bash
gcc \
src/main.c \
src/menu.c \
src/lista.c \
src/arquivo.c \
src/criptografia.c \
src/util.c \
-Iinclude \
-o BibliotecaMagica \
-Wall \
-Wextra \
-std=c11
```

---

## Execução

Após a compilação, execute o programa informando o nome do arquivo CSV que será utilizado para armazenar os dados da biblioteca.

Substitua **`<arquivo.csv>`** pelo nome do arquivo desejado.

### Linux

```bash
./build/BibliotecaMagica <arquivo.csv>
```

ou, caso tenha compilado manualmente:

```bash
./BibliotecaMagica <arquivo.csv>
```

### Windows

```cmd
BibliotecaMagica.exe <arquivo.csv>
```

### Exemplos

```bash
./build/BibliotecaMagica data/biblioteca.csv
```

```bash
./build/BibliotecaMagica livros.csv
```

```bash
./build/BibliotecaMagica inventario.csv
```

Caso o arquivo informado não exista, o programa iniciará com uma biblioteca vazia e criará automaticamente o arquivo ao encerrar a execução. Caso o arquivo já exista, os dados serão carregados automaticamente no início da execução.

---

# Menu do Sistema

Durante a execução o programa permanece em um loop até que o usuário escolha a opção **Sair**.

```text
=========================================
          BIBLIOTECA MAGICA
=========================================

1 - Cadastrar livro
2 - Deletar livro
3 - Mostrar livro
4 - Editar livro
5 - Listar livros
6 - Sair

Escolha uma opcao:
```

---

# Exemplos de Utilização

## 1 - Cadastrar Livro

```text
Titulo:
Grimorio das Sombras

Autor:
Valdris Mourne

Nascimento do autor

Dia: 12
Mes: 03
Ano: 874

Data de escrita

Dia: 07
Mes: 11
Ano: 1203

Livro cadastrado com sucesso.
ID atribuido: 1
```

---

## 2 - Deletar Livro

```text
Digite o ID:

2

Livro removido com sucesso.
```

Caso o livro não exista:

```text
Digite o ID:

20

Livro nao encontrado.
```

---

## 3 - Mostrar Livro

```text
Digite o ID:

1

----------------------------------------

ID: 1

Titulo:
Grimorio das Sombras

Autor:
Valdris Mourne

Nascimento:
12/03/874

Data de escrita:
07/11/1203

----------------------------------------
```

---

## 4 - Editar Livro

```text
Digite o ID:

1

Novo titulo:
Grimorio Supremo

Novo autor:
Valdris Mourne

Novo nascimento:

15
04
874

Nova data de escrita:

18
09
1210

Livro atualizado com sucesso.
```

---

## 5 - Listar Livros

```text
=========================================
LIVROS CADASTRADOS
=========================================

ID: 1
Titulo: Grimorio das Sombras

ID: 2
Titulo: Codex da Lua Vermelha

ID: 3
Titulo: Tomo do Vazio Eterno

-----------------------------------------

Total de livros: 3
```

---

# Validações

O sistema realiza diversas validações para evitar inconsistências.

Entre elas:

* Não permite IDs duplicados.
* Não permite vírgulas no título.
* Não permite vírgulas no nome do autor.
* Trata automaticamente arquivos inexistentes.
* Valida entradas numéricas.
* Libera toda a memória antes do encerramento.

---

# Gerenciamento de Memória

Toda a memória é alocada dinamicamente.

Cada livro corresponde a um nó da lista encadeada.

Ao remover um livro:

* a memória do nó é liberada utilizando `free()`.

Ao finalizar o programa:

* toda a lista é desalocada.

---

# Integrantes

Preencher com os integrantes do grupo.

* Ana Júlia Mendonça Inacio
* Gabriel Bortolosi de Faria Kotter
* Pedro Henrique Ramos Bento
* Ronan Vieira do Carmo Junior

---

# Licença

Projeto desenvolvido exclusivamente para fins acadêmicos como parte da disciplina de Introdução à Programação.
