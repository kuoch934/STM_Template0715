/*
 * TIM_IT.cpp
 *
 *  Created on: Jul 11, 2024
 *      Author: jw621
 */

#include "TIM_IT.h"
#include "ros_port.h"
#include "dc_motor.h"


int t_ms = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		t_ms++; //for debbugging
		speed.linear.x = 1;
	}
}

void TIM_Start(){
    HAL_TIM_Base_Start_IT(&htim2);
}


