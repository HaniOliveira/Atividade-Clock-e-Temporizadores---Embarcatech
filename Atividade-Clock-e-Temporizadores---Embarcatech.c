#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Definição dos pinos do LED RGB
#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

// Variável global para controlar o estado do semáforo
volatile int estado_semaforo = 0;

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t)
{
    // Alterna entre os estados do semáforo
    switch (estado_semaforo)
    {
    case 0: // Vermelho -> Amarelo
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_AMARELO, 1);
        gpio_put(LED_VERDE, 0);
        estado_semaforo = 1;
        printf("Sinal Amarelo\n");
        break;

    case 1: // Amarelo -> Verde
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 1);
        estado_semaforo = 2;
        printf("Sinal Verde\n");
        break;

    case 2: // Verde -> Vermelho
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 0);
        estado_semaforo = 0;
        printf("Sinal Vermelho\n");
        break;
    }
    return true;
}

int main()
{
    stdio_init_all();

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicia com o LED vermelho aceso
    gpio_put(LED_VERMELHO, 1);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    // Configura o temporizador para 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true)
    {
        printf("Sistema de semáforo em funcionamento...\n");
        sleep_ms(1000);
    }
}
