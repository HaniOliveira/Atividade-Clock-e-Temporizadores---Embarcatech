# Projeto Semáforo com Raspberry Pi Pico

Este projeto implementa um sistema de semáforo utilizando um Raspberry Pi Pico e LEDs RGB. O sistema alterna automaticamente entre as cores vermelho, amarelo e verde em intervalos regulares.

## Componentes Necessários

- 1x Raspberry Pi Pico
- 1x LED Vermelho
- 1x LED Amarelo
- 1x LED Verde
- 3x Resistores (220Ω)
- Jumpers

## Conexões

- LED Vermelho: GPIO 11
- LED Amarelo: GPIO 12
- LED Verde: GPIO 13

## Funcionamento

O sistema funciona da seguinte maneira:

1. Inicia com o sinal vermelho
2. A cada 3 segundos, alterna na seguinte sequência:
   - Vermelho → Amarelo
   - Amarelo → Verde
   - Verde → Vermelho

## Características

- Utiliza temporizadores (timers) para controle automático da sequência
- Feedback via console serial para monitoramento do estado atual
- Sistema de controle baseado em estados

## Monitoramento

O sistema imprime mensagens no console serial indicando:

- O estado atual do semáforo
- Confirmação de funcionamento do sistema
