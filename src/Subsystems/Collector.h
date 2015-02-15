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

//		enum Collect{Rightroller=0,Leftroller=1};
//		Relay relay[2];
	    Relay *Rightroller;
	    Relay *Leftroller;
	    Talon *

		int	RUNNING = 0;

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Collector();
//	void InitDefaultCommand();
	void collect(Joystick* stick,Joystick* padone);
};


#endif /* SRC_SUBSYSTEMS_COLLECTOR_H_ */
