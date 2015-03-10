/*
 * Collector.h
 *
 *  Created on: Feb 14, 2015
 *      Author: ausin
 */

#ifndef SRC_SUBSYSTEMS_COLLECTOR_H_
#define SRC_SUBSYSTEMS_COLLECTOR_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"


class Collector : public Subsystem
{
	    Relay Rightroller;
	    Relay Leftroller;
	    Talon arms;
	    int start;
		int	RUNNING;
		int runwheels;
		bool outmovebutton;
		bool inmovebutton;
		bool reversewheel;
		bool clockwise;
		bool counterclockwise;
		bool off;
		double armspower;


private:


public:
	Collector();

	void collect(Joystick* stick,Joystick* padone,Joystick* secondstick);
};


#endif /* SRC_SUBSYSTEMS_COLLECTOR_H_ */
