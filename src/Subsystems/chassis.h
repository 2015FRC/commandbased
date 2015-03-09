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
	typedef enum{Initial,Movingforward,Stopmoving}Autostate;

	PowerDistributionPanel pdp;
	Talon Rightfront;
	Talon Rightrear;
	Talon Leftfront;
	Talon Leftrear;
	Timer autoTimer;
	double passedtime;
	Autostate autostate;
	float x;
	float y;
	float z;
	float xo;
	float yo;
	float zo;
	float rawpower;
	float power;
	float rawpowero;
	float powero;
	float FR;
	float RR;
	float FL;
	float BL;
	double timestart;
	bool override;

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	void setmotorsfromjoystick(float x,float y,float z,float power);
public:
	Chassis();
	void InitDefaultCommand();
	void update(Joystick* stick,Joystick* padone, Joystick* secondstick);
	void autoupdate(Joystick* padone);



};


#endif /* SRC_SUBSYSTEMS_CHASSIS_H_ */
