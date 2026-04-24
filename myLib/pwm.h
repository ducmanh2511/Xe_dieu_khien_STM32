#ifndef PWM_H
#define PWM_H
#include "stm32f1xx_hal.h"
void pwm_set_duty(TIM_HandleTypeDef * tim,uint16_t channel, uint8_t duty);
#endif