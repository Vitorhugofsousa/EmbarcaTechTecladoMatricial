#include "perifericos.h"
#include "pico/stdlib.h"

#define gpio_led_red 18
#define gpio_led_green 19
#define gpio_led_blue 20
#define gpio_buzzer 21

// Função para ativar e desligar leds
void piscar_led(uint gpio_led)
{                            // Função que faz o led piscar com base no GPIO passado
  gpio_put(gpio_led, true);  // Ligar o led
  sleep_ms(2000);            // Tempo de espera em milissegundos
  gpio_put(gpio_led, false); // Desligar o led
}

void pisca_led_branco()
{
  gpio_put(gpio_led_red, 1);
  gpio_put(gpio_led_green, 1);
  gpio_put(gpio_led_blue, 1);
  sleep_ms(2000);

  gpio_put(gpio_led_red, 0);
  gpio_put(gpio_led_green, 0);
  gpio_put(gpio_led_blue, 0);
}

void acionar_buzzer()
{
  gpio_put(gpio_buzzer, 1); // Liga o buzzer
  sleep_ms(2000);           // Emite som por 2000ms
  gpio_put(gpio_buzzer, 0); // Desliga o buzzer
}