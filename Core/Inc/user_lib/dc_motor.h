/*
 * dc_motor.h
 *
 *  Created on: Jul 10, 2024
 *      Author: jw621
 */

#ifndef INC_DC_MOTOR_H_
#define INC_DC_MOTOR_H_

#include "stm32f4xx_hal.h"
#include "stm32f429xx.h"

class DC_motor{
public:
	static double freq;

	DC_motor( double res, double ratio, double p, double i, double d );
	double SP = 0,PV = 0;
	double output_ratio;
	//encoder
	void encoder( TIM_HandleTypeDef *encoder_TIM );
	double reduction_ratio;
	int resolution;
	int enc;
	//PID
	void PID_PWM_ratio( double set_point, double process_value );
	double kp, ki, kd;
	//output
	void output( TIM_HandleTypeDef *PWM_TIM, uint32_t PWM_Channel, double ratio,
		GPIO_TypeDef *GPIO_A, uint16_t GPIO_Pin_A, GPIO_TypeDef *GPIO_B, uint16_t GPIO_Pin_B );
};

#endif /* INC_DC_MOTOR_H_ */
