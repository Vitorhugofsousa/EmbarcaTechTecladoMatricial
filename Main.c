#include <stdio.h>
#include "pico/stdlib.h"

#define gpio_led_red 18
#define gpio_led_green 19
#define gpio_led_blue 20
#define gpio_buzzer 21
int coluna[4] = {4, 3, 2, 1}; 
int linha[4] = {8, 7, 6, 5};
char teclas[16] = {
    '1', '2' , '3', 'A',
    '4', '5' , '6', 'B',
    '7', '8' , '9', 'C',
    '*', '0' , '#', 'D'
};

int main() {
    stdio_init_all();
    gpio_init(gpio_led_red);
    gpio_init(gpio_led_green);
    gpio_init(gpio_led_blue);
    gpio_init(gpio_buzzer);
    gpio_set_dir(gpio_led_red, GPIO_OUT);
    gpio_set_dir(gpio_led_green, GPIO_OUT);
    gpio_set_dir(gpio_led_blue, GPIO_OUT);
    gpio_set_dir(gpio_buzzer, GPIO_OUT);

    while (true) {
        sleep_ms(100);
    }
}
