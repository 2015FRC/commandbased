/*
 * collector.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: ausin
 */
#include "Collector.h"
#include "RobotMap.h"


Collector::Collector():
 	 Subsystem("Collector"),
	Rightroller(0, Relay::Direction::kBothDirections),
	Leftroller(1, Relay::Direction::kBothDirections),
	arms(4),
	start(0),
	RUNNING(0),
	runwheels(0),
	outmovebutton(0),
	inmovebutton(0),
	reversewheel(0),
	clockwise(0),
	counterclockwise(0),
	off(0),
//	rawpotposition(0),
//	potpositionoffest(0),
//	maxposition(2.0),
//	buttonpress(0),
//	partalyopenlocation(80),///////change for the location fo the arms to collect
//	centeredlocation(50),///////change for the location fo the arms to collect
//	partalyclosedlocation(40),///////change for the location fo the arms to collect
	armspower(1)
{


}

void Collector::collect(Joystick* stick,Joystick* padone,Joystick* secondstick)
{
	Relay::Value forward = (Relay::Value::kForward);
	Relay::Value reverse = (Relay::Value::kReverse);

	runwheels = secondstick->GetPOV();
	off = secondstick->GetRawButton(2);



//RUNNING
	if(runwheels < 0){

		if(off == 1){
			 Rightroller.Set(Relay::Value::kOff);
			 Leftroller.Set(Relay::Value::kOff);
		}
	}else{
switch(runwheels){
//case 3 :
case 270 :
	 Rightroller.Set(reverse);
	 Leftroller.Set(reverse);
	 break;

//case 4:
case 0 :
	 Rightroller.Set(reverse);
	 Leftroller.Set(forward);
	 break;

//case 5:
case 90 :
	 Rightroller.Set(forward);
	 Leftroller.Set(forward);

 	 break;
//case 6:
case 180 :
	 Rightroller.Set(forward);
	 Leftroller.Set(reverse);
 	 break;

 default:
	 Rightroller.Set(Relay::Value::kOff);
	 Leftroller.Set(Relay::Value::kOff);
	 }
	}


outmovebutton = secondstick->GetRawButton(7);
inmovebutton = secondstick->GetRawButton(9);
//rawpotposition = ArmAngleSensor.GetAverageVoltage();
//
//////////////initilize 0
//if(start == 0){
//	potpositionoffest = rawpotposition;
//	start = 1;
//}
//unmapedpotposition =  rawpotposition-potpositionoffset;
//potposition = unmapedpotposition/maxposition*100;
//
//
//if(outmovebutton == 1 && partiallyopenbutton == 1){
//	if(potposition <= partalyopenlocation){
//			arms.Set(armspower);
//		}else{arms.Set(0);}
//
//}else{arms.Set(0);}
//
////////////////////////////////////////////////////////////////////////////
//if(outmovebutton == 1 && centeredbutton == 1){
//	if(potposition <= centeredlocation){
//			arms.Set(armspower);
//		}else{arms.Set(0);}
//
//}else{arms.Set(0);}
//
//////////////////////////////////////////////////////////////////////////////////////
//if(outmovebutton == 1 && partiallyclosedbutton == 1){
//	if(potposition <= partalyclosedlocation){
//			arms.Set(armspower);
//		}else{arms.Set(0);}
//
//}else{arms.Set(0);}
//
//////////////////////////////////////////////////////////////////////////
//if(inmovebutton == 1 && partiallyopenbutton == 1){
//	if(potposition >= partalyopenlocation){
//			arms.Set(-armspower);
//		}else{arms.Set(0);}
//
//}else{arms.Set(0);}
//
///////////////////////////////////////////////
//if(inmovebutton == 1 && centeredbutton == 1){
//	if(potposition >= centeredlocation){
//			arms.Set(-armspower);
//		}else{arms.Set(0);}
//
//}else{arms.Set(0);}
////////////////////////
//if(inmovebutton == 1 && partiallyclosedbutton == 1){
//	if(potposition >= partalyclosedlocation){
//			arms.Set(-armspower);
//		}else{arms.Set(0);}
//
//}else{arms.Set(0);}


if(outmovebutton == 1){
	arms.Set(armspower);

}else if(inmovebutton == 1){
	arms.Set(-armspower);
}
else{arms.Set(0);}




}






