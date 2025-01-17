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

//inicializa o keypad
void inicializa_teclado(uint colunas[4], uint linhas[4], char valores_matriz[16]) {
//aguardando escrever funcao
}

//função de leitura do teclado
char ler_teclado() {
//aguardando
}

//Função para ativar e desligar leds
void piscar_periferico(uint gpio_led){   //Função que faz o led piscar com base no GPIO passado
    gpio_put(gpio_led, true);            //Ligar o led
    sleep_ms(2000);                      //Tempo de espera em milissegundos
    gpio_put(gpio_led, false);           //Desligar o led
}

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

    while (true){
        char tecla_pressionada = ler_teclado();  //chama a funcao que verifica qual tecla foi pressionada
        printf("Tecla pressionada: %c\n", tecla_pressionada);
        
        //Entrar na estrutura para verificar a tecla pressionada
        switch(tecla_pressionada){              
            case 'B':                           //Verifica se a tecla B foi pressionada
            piscar_periferico(gpio_led_red);    //Chama a funcao piscar_periferico
            break;  

            default:   
            printf("Tecla não configurada");    //caso alguma tecla fora do escopo configurado foi pressionada
        }
        sleep_ms(100); //Delay para evitar leitura repetida
    }
}
