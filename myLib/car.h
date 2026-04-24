#ifndef CAR_H
#define CAR_H
#include "stm32f1xx.h"
typedef enum{
	CAR_STOP,
	CAR_FORWARD,
	CAR_BACKWARD,
	CAR_RIGHT,
	CAR_LEFT
}CarState;
void car_control(CarState car_state,uint8_t speed);
void car_init(TIM_HandleTypeDef * tim );
#endif