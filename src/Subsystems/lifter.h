/*
 * lifter.h
 *
 *  Created on: Feb 14, 2015
 *      Author: ausin
 */

#ifndef SRC_SUBSYSTEMS_LIFTER_H_
#define SRC_SUBSYSTEMS_LIFTER_H_
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public Subsystem
{
	int allbuttons;
	Talon hookbottome;
	Talon hookmiddle;
	Talon hookgarbage;


	float hookspeed;


	bool homebottom = new DigitalInput(20);
	bool homemiddle = new DigitalInput(21);
	bool topbottom = new DigitalInput(22);
	bool homegarbage = new DigitalInput(23);
	bool topmiddle = new DigitalInput(24);
	bool topgarbage = new DigitalInput(25);
//	bool homebottom;
//	bool homemiddle;
//	bool topbottom;
//	bool homegarbage;
//	bool topmiddle ;
//	bool topgarbage;


//	DigitalInput homebottom;
//	DigitalInput homemiddle;
//	DigitalInput topbottom;
//	DigitalInput  homegarbage;
//	DigitalInput topmiddle;
//	DigitalInput topgarbage;



	bool liftbottom;
	bool lowerbottom;
	bool liftmiddle;
	bool lowermiddle;
	bool liftgarbage;
	bool lowergarbage;
	bool liftall;
	bool lowerall;
	bool off;



private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Lifter();
	void lift(Joystick* stick,Joystick* padone,Joystick* secondstick);
};
#endif // SRC_SUBSYSTEMS_LIFTER_H_

