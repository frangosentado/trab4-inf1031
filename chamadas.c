#include "chamadas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compraJogo(FILE *saida, Item *catalogo, char *nome, int quant);

void chamadaBuscaJogo(FILE *saida, Item *catalogo, char *nome);

Item *sugestao(FILE *saida, Item *catalogo, char *nome);

void printaErro(FILE *saida, int err) {
  fprintf(saida, "<status>%d</status>\n", err);
}

FILE *processarComando(FILE *entrada, Item **cat) {
  Item *catalogo = *cat;
  char comando[15];
  char nome[30];
  // fscanf(entrada, " ");
  int c = getc(entrada);
  if (c == '<') {
    FILE *saida = fopen("saida.xml", "w+");
    printf("%c\n", c);
    fscanf(entrada, "%[^>]>", comando);
    printf("%s\n", comando);
    if (strcmp(comando, "compra") == 0) {
      int quant;
      fscanf(entrada, "%[^-]-%d</compra> ", nome, &quant);
      compraJogo(saida, catalogo, nome, quant);
      // funcao compra jogo
    } else if (strcmp(comando, "busca") == 0) {
      fscanf(entrada, "%[^<]</busca> ", nome);
      chamadaBuscaJogo(saida, catalogo, nome);
      // funcao busca jogo
    } else if (strcmp(comando, "sugestao") == 0) {
      fscanf(entrada, "%[^<]</sugestao> ", nome);
      *cat = sugestao(saida, catalogo, nome);
      // funcao sugerir jogo
    }
    return saida;
  }
  return NULL;
}

void compraJogo(FILE *saida, Item *catalogo, char *nome, int quant) {
  int err;
  char *codErr = "SUCESSO";
  Item *jogoProc = buscaJogo(catalogo, nome);
  Estoque *resultado = NULL;
  if (jogoProc == NULL) {
    codErr = "JOGO NÃO EXISTENTE";
    err = nOK_jogoNaoExistente;
  } else {
    resultado = alteraEstoque(jogoProc->estoque, quant, &err);
  }
  if (err == nOK_jogoEmFalta) {
    codErr = "JOGO EM FALTA";
  }
  printaErro(saida, err);
  if (!err) {
    float valor = resultado->jogo->preco * quant;
    fprintf(saida, "<rcs>%f</rcs>\n", valor);
  } else {
    fprintf(saida, "<err>%s</err>\n", codErr);
  }
}

void chamadaBuscaJogo(FILE *saida, Item *catalogo, char *nome) {
  Item *resultado = buscaJogo(catalogo, nome);
  char sucesso[30] = "SUCESSO";
  char erro[30] = "JOGO NÃO EXISTENTE";
  char *codErr = sucesso;
  int err = OK;
  if (resultado == NULL) {
    codErr = erro;
    err = nOK_jogoNaoExistente;
    
  }
  printaErro(saida, err);
  
  if (resultado) {
    fprintf(saida, "<rbs>%s-%f</rbs>\n", resultado->jogo->nome,
            resultado->jogo->preco);
  } else {
    fprintf(saida, "<err>%s</err>\n", codErr);
  }
  
}

Item *sugestao(FILE *saida, Item *catalogo, char *nome) {
  int err;
  Item *resultado = buscaJogo(catalogo, nome);
  char sucesso[30] = "SUCESSO";
  char erro[30] = "JOGO JÁ EXISTENTE";
  char *codErr = sucesso;
  Item *novo = inserirJogo(catalogo, nome, 20.0, &err);
  if (err == nOK_jogoJaExiste) {
    codErr = erro;
  }
  printaErro(saida, err);
  if (err) {
    fprintf(saida, "<err>%s</err>\n", codErr);
  } else {
    fprintf(saida, "<rss>%s</rss>\n", codErr);
  }
  return (novo ? novo : catalogo);
}