#include "jogo.h"
#include <stdlib.h>
#include <string.h>

Jogo *criaJogo(char *nome, float preco) {
  Jogo *novo = (Jogo *)malloc(sizeof(Jogo));
  novo->nome = (char *)malloc(sizeof(char) * 30);
  strcpy(novo->nome, nome);
  novo->preco = preco;
  return novo;
}