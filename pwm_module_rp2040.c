/*
* Feito por: Jorge Palma
* Data: 08/02/2025
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define PIN_LED_RGB     12
#define PINO_SERVO      22
#define PWM_FREQ        50
#define WRAP            19531
#define DIVISOR         128.0
#define DELAY           10  // 10ms
#define INCREMENTO         5  // Incremento 

#define DUTY_180 2343  // 19531 * 0.12
#define DUTY_90 1435  // 19531 * 0.0735 
#define DUTY_0 488  // 19531 * 0.025 

void movimentacao_suave();

int main()
{
    stdio_init_all();

    gpio_set_function(PIN_LED_RGB, GPIO_FUNC_PWM);
    uint slice_led = pwm_gpio_to_slice_num(PIN_LED_RGB);
    pwm_set_clkdiv(slice_led, DIVISOR);
    pwm_set_wrap(slice_led, WRAP);
    pwm_set_enabled(slice_led, true);
    pwm_set_gpio_level(PIN_LED_RGB, DUTY_0);

    gpio_set_function(PINO_SERVO, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PINO_SERVO);

    pwm_set_clkdiv(slice, DIVISOR);
    pwm_set_wrap(slice, WRAP);
    pwm_set_enabled(slice, true);
    pwm_set_gpio_level(PINO_SERVO, DUTY_0);
    sleep_ms(1000);

    printf("Aplicando ângulo de 180 graus\n");
    pwm_set_gpio_level(PINO_SERVO, DUTY_180);
    pwm_set_gpio_level(PIN_LED_RGB, DUTY_180);
    sleep_ms(5000);

    printf("Aplicando ângulo de 90 graus\n");
    pwm_set_gpio_level(PINO_SERVO, DUTY_90);
    pwm_set_gpio_level(PIN_LED_RGB, DUTY_90);
    sleep_ms(5000);

    printf("Aplicando ângulo de 0 graus\n");
    pwm_set_gpio_level(PINO_SERVO, DUTY_0);
    pwm_set_gpio_level(PIN_LED_RGB, DUTY_0);
    sleep_ms(5000);

    printf("Entrando no modo de transicao suave!\n");
    while(true)
    {
        for (int i = DUTY_0; i <= DUTY_180; i+=INCREMENTO)
        {
            pwm_set_gpio_level(PINO_SERVO, i);
            pwm_set_gpio_level(PIN_LED_RGB, i);
            sleep_ms(10);
        }

        for (int i = DUTY_180; i >= DUTY_0; i-=INCREMENTO)
        {
            pwm_set_gpio_level(PINO_SERVO, i);
            pwm_set_gpio_level(PIN_LED_RGB, i);
            sleep_ms(10);
        }
    }

    return 0;
}
