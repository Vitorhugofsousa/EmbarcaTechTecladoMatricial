#include <stdio.h>
#include "pico/stdlib.h"
#include "teclado.h"
#include "perifericos.h"

#define gpio_led_red 18
#define gpio_led_green 19
#define gpio_led_blue 20
#define gpio_buzzer 21

// definição das colunas e das linhas e mapeamento do teclado
uint8_t coluna[4] = {4, 3, 2, 1};
uint8_t linha[4] = {8, 7, 6, 5};

int main()
{
  stdio_init_all();
  gpio_init(gpio_led_red);
  gpio_init(gpio_led_green);
  gpio_init(gpio_led_blue);
  gpio_init(gpio_buzzer);
  gpio_set_dir(gpio_led_red, GPIO_OUT);
  gpio_set_dir(gpio_led_green, GPIO_OUT);
  gpio_set_dir(gpio_led_blue, GPIO_OUT);
  gpio_set_dir(gpio_buzzer, GPIO_OUT);

  inicializar_teclado(coluna, linha);

  while (true)
  {
    char tecla_pressionada = ler_teclado(coluna, linha); // Atribui a variável a tecla pressionada ao chamar a função

    if (tecla_pressionada)
    {
      printf("Tecla pressionada: %c\n", tecla_pressionada);

      switch (tecla_pressionada)
      { // Analisa a tecla pressionada e executa a ação definido a ela
      case 'A':
        piscar_led(gpio_led_blue); // Verifica se a tecla A foi pressionada
        break;

      case 'B':                   // Verifica se a tecla B foi pressionada
        piscar_led(gpio_led_red); // Chama a funcao piscar_led
        break;

      case 'C':                     // Verifica se  a tecla C foi pressionada
        piscar_led(gpio_led_green); // Chama a função piscar_led
        break;

      case 'D': // Piscar luz branca uma vez
        pisca_led_branco();
        break;
      case '#': // Verifica se a tecla # foi pressionada
        acionar_buzzer();
        break;

      default:
        printf("Tecla não configurada\n");
      }
      sleep_ms(100); // Delay para evitar leitura repetida
    }
  }
}
