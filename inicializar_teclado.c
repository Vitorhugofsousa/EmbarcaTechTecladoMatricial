#include "teclado.h"
#include "pico/stdlib.h"

// Inicialização das GPIOs do teclado
uint8_t colunas[4] = {4, 3, 2, 1};
uint8_t linhas[4] = {8, 7, 6, 5};
char teclas[4][4] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'};

void inicializar_teclado() {
  for (int i = 0; i < 4; i++) {
    gpio_init(linhas[i]);
    gpio_set_dir(linhas[i], GPIO_OUT);
    gpio_put(linhas[i], 1); // Inicialmente em HIGH

    gpio_init(colunas[i]);
    gpio_set_dir(colunas[i], GPIO_IN);
    gpio_pull_up(colunas[i]); // Habilita pull-up nas colunas
  }
}