#include <stdio.h>

void confereParametro(int scanValue, int scanCheck, int *valid) {
  if (scanValue != scanCheck) {
    printf("PARÂMETRO INVÁLIDO!\n");
    *valid = 0;
  };
}