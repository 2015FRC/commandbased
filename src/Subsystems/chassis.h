/*
 * chassis.h
 *
 *  Created on: Feb 13, 2015
 *      Author: ausin
 */

#ifndef SRC_SUBSYSTEMS_CHASSIS_H_
#define SRC_SUBSYSTEMS_CHASSIS_H_

#include "WPILib.h"
#include "Commands/Subsystem.h"


class Chassis: public Subsystem
{


	Talon Rightfront;
	Talon Rightrear;
	Talon Leftfront;
	Talon Leftrear;
	float x;
	float y;
	float z;
	bool DriveToggle;
	float rawpower;
	double power;
	float FR;
	float RR;
	float FL;
	float BL;


private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Chassis();
	void InitDefaultCommand();
	void update(Joystick* stick,Joystick* padone);



};


#endif /* SRC_SUBSYSTEMS_CHASSIS_H_ */
