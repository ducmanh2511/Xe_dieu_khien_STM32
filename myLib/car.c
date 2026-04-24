#include "car.h"
#include "motor.h"
Motor_Typedef motor_left;
Motor_Typedef motor_right;
void car_control(CarState car_state,uint8_t speed){
	switch(car_state){
		case CAR_STOP :
			motor_control(&motor_right,MOTOR_STOP,0);
	   	motor_control(&motor_left,MOTOR_STOP,0);
			break;
		case CAR_FORWARD :
			motor_control(&motor_right,MOTOR_CW,speed);
	  	motor_control(&motor_left,MOTOR_CW,speed);
		 break;
		case CAR_BACKWARD :
			motor_control(&motor_right,MOTOR_CCW,speed);
		  motor_control(&motor_left,MOTOR_CCW,speed);
			break;
		case CAR_RIGHT :
			motor_control(&motor_right,MOTOR_STOP,0);
		  motor_control(&motor_left,MOTOR_CW,speed);
			break ;
		case CAR_LEFT :
			motor_control(&motor_left,MOTOR_STOP,0);
		  motor_control(&motor_right,MOTOR_CW,speed);
		break;
			
		default :
			break;
		
	}
}
void car_init(TIM_HandleTypeDef * tim ) {
	 motor_init(&motor_right,GPIOB,GPIO_PIN_14,GPIOB,GPIO_PIN_13,tim, TIM_CHANNEL_1);
	 motor_init(&motor_left,GPIOB,GPIO_PIN_15,GPIOB,GPIO_PIN_12,tim, TIM_CHANNEL_2);
	car_control(CAR_STOP,0);
}

