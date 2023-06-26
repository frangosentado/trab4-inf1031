#include "catalogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Item *criaCatalogo() {
  Item *novo = NULL;
  return novo;
}

Item *criaItem(Jogo *j) {
  if (j == NULL) return NULL;
  Item *novo = (Item *)malloc(sizeof(Item));
  novo->jogo = j;
  Estoque *estoque = (Estoque *)malloc(sizeof(Estoque));
  estoque->quantidade = 10;
  estoque->jogo = j;
  novo->estoque = estoque;
  return novo;
}

Item *inserirJogo(Item *catalogo, char *nome, float preco, int *erro) {
  if (preco < 0) {
    *(erro) = nOK_dadoInvalido;
    return catalogo;
  }
  Item *existente = buscaJogo(catalogo, nome);
  if (existente == NULL) {
    Jogo *novoJogo = criaJogo(nome, preco);
    Item *novo = criaItem(novoJogo);
    novo->ant = NULL;
    novo->prox = catalogo;
    if (catalogo != NULL) {
      catalogo->ant = novo;
    }
    *(erro) = OK;
    return novo;
  } else {
    *(erro) = nOK_jogoJaExiste;
  }
  return catalogo;
}

void mostrarCatalogo(Item *catalogo) {
  printf("\n-----CATALOGO LOCADORA-----\n");
  while (catalogo != NULL) {
    printf("Nome do jogo: %s\t ------ Quantidade: %d\t ------ Preço: %.2f\n",
           catalogo->jogo->nome, catalogo->estoque->quantidade,
           catalogo->jogo->preco);
    catalogo = catalogo->prox;
  }
  printf("----- FIM DO CATÁLOGO -----\n");
}

Item *buscaJogo(Item *catalogo, char *nomeJogo) {
  if (nomeJogo == NULL)
    return NULL;
  while (catalogo != NULL && (strcmp(catalogo->jogo->nome, nomeJogo) != 0)) {
    catalogo = catalogo->prox;
  }
  return catalogo;
}

Item *alteraPreco(Item *catalogo, char *nomeJogo, float *novoPreco, int *erro) {
  Item *encontrado = buscaJogo(catalogo, nomeJogo);
  if (encontrado != NULL) {
    encontrado->jogo->preco = *novoPreco;
    *(erro) = OK;
    return encontrado;
  } else {
    *(erro) = nOK_jogoNaoExistente;
  }

  return encontrado;
}

Item *alteraNome(Item *catalogo, char *nomeJogo, char *novoNome, int *erro) {
  Item *encontrado = buscaJogo(catalogo, nomeJogo);
  if (sizeof(novoNome) != sizeof(char *)){
    *(erro) = nOK_dadoInvalido;
    return encontrado;
  }
  if (encontrado != NULL) {
    strcpy(encontrado->jogo->nome, novoNome);
    *(erro) = OK;
  } else {
    *(erro) = nOK_jogoNaoExistente;
  }
  return encontrado;
}

Item *alteraQuantidade(Item *catalogo, char *nomeJogo, int *desvio, int *erro) {
  Item *encontrado = buscaJogo(catalogo, nomeJogo);
  alteraEstoque(catalogo->estoque, *desvio, erro);
  return encontrado;
}

Item *removeJogo(Item *catalogo, char *nomeJogo, int *erro) {
  Item *encontrado = buscaJogo(catalogo, nomeJogo);
  if (encontrado != NULL) {
    Item *anterior = encontrado->ant;
    if (anterior == NULL) {
      Item *ret = encontrado->prox;
      if (ret) {
        ret->ant = NULL;
      }
      liberaItem(encontrado);
      return ret;
    }
    anterior->prox = encontrado->prox;
    liberaItem(encontrado);
    *(erro) = OK;
  } else {
    *(erro) = nOK_jogoNaoExistente;
  }
  return catalogo;
}

Item *alteraWrapper(funcp f, Item *catalogo, char *nomeJogo, void *novo,
                    int *erro) {
  if (catalogo != NULL) {
    Item *resp = f(catalogo, nomeJogo, novo, erro);
    return resp;
  }
  return NULL;
}

void liberaItem(Item *item) {
  free(item->jogo);
  free(item->estoque);
  free(item);
}

void trataErros(int *erro) {
  if (*(erro) == nOK_jogoNaoExistente) {
    printf("ERRO: O JOGO NÃO EXISTE NO CATÁLOGO\n");
  } else if (*(erro) == nOK_jogoJaExiste) {
    printf("ERRO: O JOGO JÁ EXISTE NO CATÁLOGO\n");
  } else if (*(erro) == nOK_dadoInvalido) {
    printf("ERRO: DADO INSERIDO INVÁLIDO\n");
  } else {
    printf("SUCESSO!\n");
  }
}