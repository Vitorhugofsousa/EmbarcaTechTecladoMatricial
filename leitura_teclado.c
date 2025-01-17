//função de leitura do teclado
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