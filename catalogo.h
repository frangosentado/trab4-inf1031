#include "estoque.h"

enum Erros {
  OK,
  nOK_jogoNaoExistente,
  nOK_jogoJaExiste,
  nOK_dadoInvalido,
  nOK_jogoEmFalta,
};

typedef struct item {
  Jogo *jogo;
  Estoque *estoque;
  struct item *prox;
  struct item *ant;
} Item;

// typedef Item *(funcp)(Item *, char *, void *, int *erro);
typedef Item *(funcp)();

Item *criaCatalogo();

Item *inserirJogo(Item *catalogo, char *nome, float preco, int *erro);

void mostrarCatalogo(Item *catalogo);

Item *alteraPreco(Item *catalogo, char *nomeJogo, float *novoPreco, int *erro);

Item *alteraNome(Item *catalogo, char *nomeJogo, char *novoNome, int *erro);

Item *alteraQuantidade(Item *catalogo, char *nomeJogo, int *desvio, int *erro);

Item *removeJogo(Item *catalogo, char *nomeJogo, int *erro);

Item *buscaJogo(Item *catalogo, char *nomeJogo);

Item *alteraWrapper(funcp f, Item *catalogo, char *nomeJogo, void *novo,
                    int *erro);

void liberaItem(Item *item);

void trataErros(int *erro);