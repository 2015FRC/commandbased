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
	    Relay Rightroller;
	    Relay Leftroller;
	    Talon arms;


	    int start;

	    double potval;
	    AnalogInput ArmAngleSensor;

///////////////////////////
		int	RUNNING;

//////////////////////arms
		int fullyopen;
		int fullyclosed;
		int partiallyopen;
		int centered;
		int partalyclsoed;
		int buttonpress;


		double unmapedpotposition;
		double potpositionoffset;
		double mappedpotposition;
		double potposition;
		double maxposition;///////////voltage we mesure form the open and close(difference)
		double armspower;


		//////////////////buttons on joystick and pad
		bool partiallyopenbutton;
		bool centeredbutton;
		bool partiallyclosedbutton;

		bool outmovebutton;
		bool inmovebutton;

		bool outerbutton;
		bool middlebutton;
		bool innerbutton;
		bool runwheels;

		bool reversewheel;
		bool clockwise;
		bool counterclockwise;
		bool off;
		double rawpotposition;
		double potpositionoffest;

		double partalyopenlocation;
		double centeredlocation;
		double partalyclosedlocation;


private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Collector();
//	void InitDefaultCommand();
	void collect(Joystick* stick,Joystick* padone);
};


#endif /* SRC_SUBSYSTEMS_COLLECTOR_H_ */
