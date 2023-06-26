#include "estoque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Estoque *alteraEstoque(Estoque *estoque, int quant, int *erro) {
  *erro = 0;
  if ((estoque->quantidade + quant) < 0) {
    estoque->quantidade += 10;
    *erro = 3;
  } else {
    estoque->quantidade += quant;
  }
  return estoque;
}