/*
 * dc_motor.cpp
 *
 *  Created on: Aug 25, 2024
 *      Author: Kch93
 */

#include "dc_motor.h"
#include "math.h"
#define pi 3.1415926535897932384

//motor Instance
DC_motor::DC_motor( double res, double ratio, double p, double i, double d ){
	/*encoder parameter*/
	this->reduction_ratio = ratio;
	this->resolution = res;
	/*PID parameter*/
	this->kp = p;
	this->ki = i;
	this->kd = d;
}
// step 1
/*return angular velocity (rad/s) */
void DC_motor::encoder(TIM_HandleTypeDef *encoder_TIM){
	enc = __HAL_TIM_GetCounter(encoder_TIM);
	__HAL_TIM_SetCounter(encoder_TIM,0);
	PV = (double) enc/(4*resolution*reduction_ratio*freq*2*pi);
}
// step 2
/*return pwm ratio*/
void DC_motor::PID_PWM_ratio( double set_point, double process_value ){
	double error, differential, u = 0;
	static double integral, prev_u = 0;
	//Proportion
	error = set_point - process_value;
	//integral
	integral += error / freq;
	if (ki * integral > 1) integral = 1/ki;
	else if (ki * integral < -1) integral = -1/ki;
	//differential
	differential = (u - prev_u) * freq;
	prev_u = u;
	//PWM_Ratio
	u = kp * error + ki * integral + kd * differential;
	if (u > 1) u = 1;
	else if (u < -1) u = -1;
	output_ratio = u;
}
// step 3
/*GPIO output*/
void DC_motor::output(TIM_HandleTypeDef *PWM_TIM, uint32_t PWM_Channel, double PWM_ratio,
		GPIO_TypeDef *GPIO_A, uint16_t GPIO_Pin_A, GPIO_TypeDef *GPIO_B, uint16_t GPIO_Pin_B){

	int Pulse = (int) PWM_ratio*PWM_TIM->Instance->ARR;
	__HAL_TIM_SET_COMPARE(PWM_TIM, PWM_Channel, abs(Pulse));

	if(Pulse >= 0){
		HAL_GPIO_WritePin(GPIO_A, GPIO_Pin_A, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIO_B, GPIO_Pin_B, GPIO_PIN_RESET);
	}
	else{
		HAL_GPIO_WritePin(GPIO_A, GPIO_Pin_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIO_B, GPIO_Pin_B, GPIO_PIN_SET);
	}
}
