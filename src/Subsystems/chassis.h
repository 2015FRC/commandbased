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

//	enum Drive{RightFront=0,RightRear=1,LeftFront=2,LeftRear=3};
//	Talon Motor[4];

	Talon *Rightfront;
	Talon *Rightrear;
	Talon *Leftfront;
	Talon *Leftrear;
	bool DriveToggle;


private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Chassis();
	void InitDefaultCommand();
	void update(Joystick* stick,Joystick* padone);



};


#endif /* SRC_SUBSYSTEMS_CHASSIS_H_ */
