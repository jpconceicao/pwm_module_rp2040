# Controle de Servo Motor com Raspberry Pi Pico W

## Descrição
Este projeto utiliza a Raspberry Pi Pico W para controlar um servomotor por meio do módulo PWM. O sistema ajusta o ângulo do servo entre 0°, 90° e 180°, além de realizar uma transição suave entre essas posições. Além disso, um LED RGB (GPIO 12) é controlado simultaneamente para refletir os níveis de PWM aplicados ao servo.

## Autor
**Jorge Palma**


## Componentes Utilizados
- Raspberry Pi Pico W
- Servomotor (conectado ao GPIO 22)
- LED RGB (conectado ao GPIO 12)

## Funcionamento
1. Inicializa o PWM no GPIO 22 para o servo e no GPIO 12 para o LED RGB.
2. Ajusta o ângulo do servo para:
   - **180°** (Pulso de 2.343 ms)
   - **90°** (Pulso de 1.435 ms)
   - **0°** (Pulso de 0.488 ms)
3. Alterna entre essas posições com um tempo de espera de 5 segundos.
4. Ativa uma movimentação suave do servo entre 0° e 180° em incrementos de 5 µs a cada 10 ms.

## Definições de PWM
- **Frequência:** 50 Hz
- **Período:** 20 ms (19531 ticks do PWM)
- **Divisor de Clock:** 128.0
- **Duty Cycle para cada ângulo:**
  - 180°: 2343/19531 (~12%)
  - 90°: 1435/19531 (~7.35%)
  - 0°: 488/19531 (~2.5%)

## Como Usar
1. Carregar o código na Raspberry Pi Pico W usando o Pico SDK.
2. Conectar o servo motor ao GPIO 22 e o LED RGB ao GPIO 12.
3. Executar o código e observar a movimentação do servo e a variação da intensidade do LED RGB.

## Observações
- O LED RGB apresenta variação no brilho conforme a movimentação do servo, pois compartilha o mesmo PWM.
- A movimentação suave do servo evita mudanças bruscas e melhora a precisão do posicionamento.
