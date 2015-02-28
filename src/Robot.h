/*
 * Robot.h
 *
 *  Created on: Feb 13, 2015
 *      Author: ausin
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

//#include "WPLlib.h"
#include <cstdlib>



class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	Joystick stick;
	Joystick secondstick;
	Joystick padone;
	Chassis chassis;
	Collector _collector;
	Lifter lifter;



public:
	 Robot();

	void DisabledPeriodic();

	void AutonomousInit();

	void AutonomousPeriodic();

	void TeleopInit();

	void TeleopPeriodic();

	void TestPeriodic();

};



#endif /* SRC_ROBOT_H_ */
