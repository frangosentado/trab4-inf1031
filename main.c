#include "chamadas.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

int main(void) {
  Item *cat = criaCatalogo();
  int err;
  int valid;
  char comando[10];
  char nom[30];
  float prec;
  char novoNom[30];
  FILE *entrada = fopen("entrada.xml", "r");
  // FILE *saida = fopen("saida.xml", "wr");
  printf("------LISTA DE COMANDOS ACEITOS PELO SISTEMA------\n");
  printf("ij ----------- insere um jogo de nome n e preço p no catálogo\n");
  printf("bj ----------- busca um jogo de nome n\n");
  printf("ap ----------- altera o preço do jogo n para p\n");
  printf("an ----------- altera o nome do jogo n para m\n");
  printf("rm ----------- remove o jogo n\n");
  printf("mc ----------- mostra o catálogo\n");
  printf("---------------------------------------------------\n");
  printf("Digite um comando: ");
  int numComando = scanf("%s", comando);
  while (strcmp(comando, "exit") != 0) {
    err = 0;
    valid = 1;
    // incluir chamada de funcao para checar arquivo
    if (numComando != 1) {
      continue;
    } else if (strcmp(comando, "ij") == 0) { // comando de inserir jogo
      do {
        printf("Insira o nome do jogo a ser inserido: "); // confere
                                                          // se o nome
                                                          // do jogo
                                                          // foi
                                                          // inserido
        int nomeScan = scanf("%s", nom);
        confereParametro(nomeScan, 1, &valid);
      } while (!valid);

      do {
        printf("Insira o preço do jogo inserido: "); // confere se o preço do
                                                     // jogo foi inserido
        int precScan = scanf("%f", &prec);
        confereParametro(precScan, 1, &valid);
      } while (!valid);

      Item *result = inserirJogo(cat, nom, prec, &err); // chama a função
      if (result != NULL) {                             // testa resultado
        cat = result;
      }
    } else if (strcmp(comando, "bj") == 0) { // comando de buscar jogo
      do {
        printf("Insira o nome do jogo: ");
        int nomeScan = scanf("%s", nom);
        confereParametro(nomeScan, 1, &valid);
      } while (!valid);

      Item *jogo = buscaJogo(cat, nom);
      if (jogo) {
        printf(
            "Nome do jogo: %s\t ------ Quantidade: %d\t ------ Preço:  R$%f\n",
            jogo->jogo->nome, jogo->estoque->quantidade, jogo->jogo->preco);
      }
    } else if (strcmp(comando, "ap") == 0) {
      do {
        printf("Insira o nome do jogo a ser modificado: ");
        int nomeScan = scanf("%s", nom);
        confereParametro(nomeScan, 1, &valid);
      } while (!valid);
      do {
        printf("Insira o novo preço para o jogo: ");
        int precScan = scanf("%f", &prec);
        confereParametro(precScan, 1, &valid);
      } while (!valid);
      Item *resultado = alteraWrapper(alteraPreco, cat, nom, &prec, &err);
    } else if (strcmp(comando, "an") == 0) {
      do {
        printf("Insira o nome do jogo a ser modificado: ");
        int nomeScan = scanf("%s", nom);
        confereParametro(nomeScan, 1, &valid);
      } while (!valid);
      do {
        printf("Insira o novo nome para o jogo: ");
        int newNameScan = scanf("%s", novoNom);
        confereParametro(newNameScan, 1, &valid);
      } while (!valid);

      Item *resultado = alteraWrapper(alteraNome, cat, nom, novoNom, &err);
    } else if (strcmp(comando, "rm") == 0) {
      do {
        printf("Insira o nome do jogo a ser removido: ");
        int nomeScan = scanf("%s", nom);
        confereParametro(nomeScan, 1, &valid);
      } while (!valid);

      Item *resultado = removeJogo(cat, nom, &err);
      cat = resultado;
      // faltam inserir os tratamentos de XML
    } else if (strcmp(comando, "mc") == 0) {
      mostrarCatalogo(cat);
    } else {
      printf("COMANDO INVÁLIDO! VEJA OS COMANDOS VÁLIDOS ACIMA\n");
      valid = 0;
    }
    trataErros(&err);
    FILE *saida = processarComando(entrada, &cat);
    if (saida) {
      fclose(saida);
    }
    fclose(entrada);
    entrada = fopen("entrada.xml", "w+");
    fclose(entrada);
    printf("Digite um comando: ");
    numComando = scanf("%s", comando);
    entrada = fopen("entrada.xml", "r");
  }
  return 0;
}