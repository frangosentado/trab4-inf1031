#include "jogo.h"
typedef struct estoque Estoque;
struct estoque {
  int quantidade;
  Jogo *jogo;
};

Estoque *alteraEstoque(Estoque *catalogo, int quant, int *erro);