// Inicialização das GPIOs do teclado
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