#include "teclado.h"
#include "pico/stdlib.h"

//função de leitura do teclado
uint8_t coluna[4] = {4, 3, 2, 1};
uint8_t linha[4] = {8, 7, 6, 5};
char teclas[4][4] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'};

char ler_teclado(uint8_t *colunas, uint8_t *linhas) {
  for (int i = 0; i < 4; i++) {
    gpio_put(linhas[i], 0);
    uint8_t result = 0;
    for (int j = 0; j < 4; j++){
      result |= gpio_get(colunas[j]);
    }
    if (result == 0) {
      char key = teclas[i][__builtin_ctz(result)];
      gpio_put(linhas[i], 1);
      return key;
    }
    gpio_put(linhas[i], 1);
  }
  return 0;
}