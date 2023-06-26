#include <stdio.h>
#include "chamadas.h"
#include "utils.h"
#include <string.h>

int testes(void)
{
  int erro = OK;
  // ---- FUNÇÃO DE CRIAR JOGO ----
  Jogo *resultado;
  printf("----TESTE FUNÇÃO DE CRIAR JOGO----\n");  
  printf("Teste 1: Criar jogo com parâmetros válidos");
  resultado = criaJogo("Doom", 10.0);
  printf("RESULTADO ESPERADO: SUCESSO!\t");
  printf("RESULTADO OBTIDO:");
  if (resultado && strcmp(resultado->nome,"Doom") == 0 && resultado->preco < 10.1 && resultado->preco > 9.9) {
    printf("SUCESSO!\n");
  } else {
    printf("FALHA!\n");
  }
  printf("\n----FIM TESTE FUNÇÃO CRIAR JOGO----\n");

  // ---- FUNÇÃO DE CRIAR ITEM ----
  Item *itemCriado;
  printf("----TESTE FUNÇÃO DE CRIAR ITEM----\n");  
  printf("Teste 1: Criar jogo com parâmetros válidos");
  resultado = criaJogo("Doom", 10.0);
  printf("RESULTADO ESPERADO: SUCESSO!\t");
  printf("RESULTADO OBTIDO:");
  if (resultado && strcmp(resultado->nome,"Doom") == 0 && resultado->preco < 10.1 && resultado->preco > 9.9) {
    printf("SUCESSO!\n");
  } else {
    printf("FALHA!\n");
  }
  printf("\n----FIM TESTE FUNÇÃO CRIAR JOGO----\n");
  
  // ---- FUNÇÃO DE INSERIR JOGO ----
  printf("----TESTE FUNÇÃO DE INSERIR JOGO----\n");  
  Item *cat = criaCatalogo();
  printf("Teste 1: Inserir jogo não existente no catálogo");
  cat = inserirJogo(cat, "Doom", 10, &erro);
  printf("RESULTADO ESPERADO: SUCESSO!\t");
  printf("RESULTADO OBTIDO:");
  trataErros(&erro);
  printf("Teste 2: Inserir jogo já existente no catálogo");
  cat = inserirJogo(cat, "Doom", 12, &erro);
  printf("RESULTADO ESPERADO: ERRO: O JOGO JÁ EXISTE NO CATÁLOGO!\t");
  printf("RESULTADO OBTIDO:");
  trataErros(&erro);
  printf("Teste 3: Inserir jogo com dado inválido");
  cat = inserirJogo(cat, "Botw", -1, &erro);
  printf("RESULTADO ESPERADO: ERRO: DADO INSERIDO INVÁLIDO\t");
  printf("RESULTADO OBTIDO:");
  trataErros(&erro);
  printf("\n----FIM TESTE FUNÇÃO INSERIR JOGOS----\n");

  // ---- FUNÇÃO DE BUSCAR JOGO ----
  printf("----TESTE FUNÇÃO DE BUSCAR JOGOS----\n");
  printf("Teste 1: buscar jogo existente\n");
  cat = buscaJogo(cat, "Doom");
  printf("RESULTADO ESPERADO: Doom\t");
  printf("RESULTADO OBTIDO %s\n:",cat->jogo->nome);

  printf("Teste 2: buscar jogo não existente");
  cat = buscaJogo(cat, "Battlefield");
  printf("RESULTADO ESPERADO: jogo fora do catalogo\t");
  printf("RESULTADO OBTIDO: ");
  if(!cat){printf("jogo fora do catalogo\n");}//conferir

  printf("----FIM DO TESTE BUSCAR JOGOS----\n");

  printf("----INICIO TESTE ALTERA NOME----\n");
  printf("\nTeste 1: alterar nome de jogo existente");
  cat = alteraNome(cat, "Doom", "DM", &erro);
  printf("RESULTADO ESPERADO: SUCESSO!\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);
  
  printf("\nTeste 2: alterar nome de jogo não existente");
  cat = alteraNome(cat, "lotr", "DM", &erro);
  printf("RESULTADO ESPERADO: ERRO: O JOGO NÃO EXISTE NO CATÁLOGO\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);
   
  printf("\nTeste 3: alterar nome com dado inválido");
  cat = alteraNome(cat, "lotr", 5, &erro);
  printf("RESULTADO ESPERADO: ERRO: O JOGO NÃO EXISTE NO CATÁLOGO\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);
  printf("----FIM TESTE ALTERA NOME----\n");

  // ---- FUNÇÃO DE ALTERAR PREÇO ----
  printf("----INICIO TESTE ALTERA PREÇO----");
  float *newprice;
  (*newprice)=12.5;
  printf("\nTeste 1: alterar preço de jogo existente");
  cat = alteraPreco(cat, "Doom", newprice, &erro);
  printf("RESULTADO ESPERADO: SUCESSO!\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);
  
  printf("\nTeste 2: alterar preço de jogo não existente");
  cat = alteraPreco(cat, "lotr", newprice, &erro);
  printf("RESULTADO ESPERADO: ERRO: O JOGO NÃO EXISTE NO CATÁLOGO\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);
   
  printf("----FIM TESTE ALTERA PREÇO----\n");

  int *des;
  (*des)=10;
  printf("----INICIO TESTE ALTERA QUANTIDADE----");
  printf("\nTeste 1: alterar quantidade com dados validos");
  cat = alteraQuantidade(cat, "Doom", des, &erro);
  printf("RESULTADO ESPERADO: SUCESSO!\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);
  
  printf("\nTeste 2: alterar preço de jogo não existente");
  cat = alteraPreco(cat, "lotr", newprice, &erro);
  printf("RESULTADO ESPERADO: ERRO: O JOGO NÃO EXISTE NO CATÁLOGO\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);
   
  printf("----FIM TESTE ALTERA QUANTIDADE----\n");
  
  printf("----INÍCIO TESTE REMOVER JOGO----\n");
  printf("\nTeste 1: remover jogo existente no catálogo;")
  return 0;
}