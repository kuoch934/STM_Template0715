/*
 * kinematic_model.cpp
 *
 *  Created on: Aug 25, 2024
 *      Author: kch93
 */

#include <kinematic_model.h>
#include <math.h>
//length parameters at Kinematic Model.h
//linear velocity unit (m/s), angular velocity unit (rad/s)

//The front of the car is in the positive x direction. Counterclockwise rotation is positive
//Mecanum -- Use the first quadrant as the number one position
//Mecanum_O
void Mecanum_O::inverse_kinetics(double Vx, double Vy, double w, double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP){
	*m1_SP = ( Vx - Vy - w*( lx + ly) )/radius;
	*m2_SP = ( Vx + Vy - w*( lx + ly) )/radius;
	*m3_SP = ( Vx - Vy + w*( lx + ly) )/radius;
	*m4_SP = ( Vx + Vy + w*( lx + ly) )/radius;
}
void Mecanum_O::forward_kinetics(double m1_PV, double m2_PV, double m3_PV, double m4_PV, double* rVx, double* rVy, double* rw){
	*rVx = ( m1_PV + m2_PV + m3_PV + m4_PV )/4*radius;
	*rVy = ( -m1_PV + m2_PV - m3_PV + m4_PV )/4*radius;
	*rw  = ( -m1_PV -m2_PV + m3_PV + m4_PV )/(4*( lx + ly ))*radius;
}

//Mecanum_X
void Mecanum_X::inverse_kinetics(double Vx, double Vy, double w, double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP){
	*m1_SP = ( Vx + Vy - w*( lx - ly) )/radius;
	*m2_SP = ( Vx - Vy + w*( lx - ly) )/radius;
	*m3_SP = ( Vx + Vy + w*( lx - ly) )/radius;
	*m4_SP = ( Vx - Vy - w*( lx - ly) )/radius;
}
void Mecanum_X::forward_kinetics(double m1_PV, double m2_PV, double m3_PV, double m4_PV, double* rVx, double* rVy, double* rw){
	*rVx = ( m1_PV + m2_PV + m3_PV + m4_PV)/4*radius;
	*rVy = ( m1_PV - m2_PV + m3_PV - m4_PV)/4*radius;
	*rw  = ( -m1_PV + m2_PV + m3_PV - m4_PV)/(4*( lx - ly ))*radius;
}

//omniwheel -- Use the Y-axis direction as the first position
//omni_3
void omni_3::inverse_kinetics(double Vx, double Vy, double w, double* m1_SP, double* m2_SP, double* m3_SP){
	*m1_SP= ( Vx - w*r )/radius;
	*m2_SP= ( -0.5*Vx + 2/sqrt(3)*Vy - w*r )/radius;
	*m3_SP= ( -0.5*Vx - 2/sqrt(3)*Vy - w*r )/radius;
}
void omni_3::forward_kinetics(double m1_PV, double m2_PV, double m3_PV, double* rVx, double* rVy, double* rw){
	*rVx = ( m1_PV*2 - m2_PV - *m3_PV )/3*radius;
	*rVy = ( m2_PV - m3_PV )*sqrt(3)/4*radius;
	*rw  = ( -m1_PV - m2_PV - m3_PV )/(3*r)*radius;
}

//omni_4
void omni_4::inverse_kinetics(double Vx, double Vy, double w, double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP){
	*m1_SP = ( Vx - w*r )/radius;
	*m2_SP = ( Vy - w*r )/radius;
	*m3_SP = ( -Vx - w*r )/radius;
	*m4_SP = ( -Vy - w*r )/radius;
}
void omni_4::forward_kinetics(double m1_PV, double m2_PV, double m3_PV, double m4_PV, double* rVx, double* rVy, double* rw){
	*rVx = ( m1_PV - m3_PV )/2*radius;
	*rVy = ( m2_PV - m4_PV )*sqrt(3)/2*radius;
	*rw  = ( -m1_PV - m2_PV - m3_PV - m4_PV )/(4*r)*radius;
}

//differential_wheel -- Use the Y-axis direction as the first position
void differential_wheel::inverse_kinetics(double V, double w, double* m1_SP, double* m2_SP){
	*m1_SP = ( V - w*r )/radius;
	*m2_SP = ( -V - w*r )/radius;
}
void differential_wheel::forward_kinetics(double m1_PV, double m2_PV, double* rV, double* rw){
	*rV = ( m1_PV - m2_PV )/2*radius;
	*rw  = ( -m1_PV - m2_PV )/(2*r)*radius;
}
