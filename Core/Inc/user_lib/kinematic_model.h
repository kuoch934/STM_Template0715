/*
 * kinematic_model.h
 *
 *  Created on: Jul 11, 2024
 *      Author: user
 */

#ifndef INC_KINEMATIC_MODEL_H_
#define INC_KINEMATIC_MODEL_H_

namespace Mecanum_O{
	//wheel_data (m)
	const double lx = 193.39, ly = 236.555;
	const double radius = 129;
	//transformation
	void inverse_kinetics(double Vx, double Vy, double w, double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP);
	void forward_kinetics(double m1_PV, double m2_PV, double m3_PV, double m4_PV, double* rVx, double* rVy, double* rw);
}

namespace Mecanum_X{
	//wheel_data (m)
	const double lx = 10, ly = 10;
	const double radius = 129;
	//transformation
	void inverse_kinetics(double Vx, double Vy, double w, double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP);
	void forward_kinetics(double m1_PV, double m2_PV, double m3_PV, double m4_PV, double* rVx, double* rVy, double* rw);
}

namespace omni_3{
	//wheel_data (m)
	const double r = 193.39;
	const double radius = 129;
	//transformation
	void inverse_kinetics(double Vx, double Vy, double w, double* m1_SP, double* m2_SP, double* m3_SP);
	void forward_kinetics(double m1_PV, double m2_PV, double m3_PV, double* rVx, double* rVy, double* rw);
}

namespace omni_4{
	//wheel_data (m)
	const double r = 193.39;
	const double radius = 129;
	//transformation
	void inverse_kinetics(double Vx, double Vy, double w, double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP);
	void forward_kinetics(double m1_PV, double m2_PV, double m3_PV, double m4_PV, double* rVx, double* rVy, double* rw);
}

namespace differential_wheel{
	//wheel_data (m)
	const double r = 193.39;
	const double radius = 129;
	//transformation
	void inverse_kinetics(double V, double w, double* m1_SP, double* m2_SP);
	void forward_kinetics(double m1_PV, double m2_PV, double* rV, double* rw);
}

#endif /* INC_KINEMATIC_MODEL_H_ */
