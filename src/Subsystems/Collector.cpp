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
	ArmAngleSensor(0),
	Rightroller(0, Relay::Direction::kBothDirections),
	Leftroller(1, Relay::Direction::kBothDirections),
	arms(4),
	start(0),
	RUNNING(0),
	partiallyopenbutton(0),
	centeredbutton(0),
	partiallyclosedbutton(0),
	middlebutton(0),
	innerbutton(0),
	runwheels(0),
	outmovebutton(0),
	inmovebutton(0),
	reversewheel(0),
	clockwise(0),
	counterclockwise(0),
	off(0),
	rawpotposition(0),
	potpositionoffest(0),
	maxposition(2.0),
	buttonpress(0),
	partalyopenlocation(80),///////change for the location fo the arms to collect
	centeredlocation(50),///////change for the location fo the arms to collect
	partalyclosedlocation(40),///////change for the location fo the arms to collect
	armspower(1)
{


}

void Collector::collect(Joystick* stick,Joystick* padone,Joystick* secondstick)
{
	Relay::Value forward = (Relay::Value::kForward);
	Relay::Value reverse = (Relay::Value::kReverse);

	runwheels = secondstick->GetPOV();
//	runwheels = secondstick->GetRawButton(5) ;
//	reversewheel = secondstick->GetRawButton(3);
//	clockwise = secondstick->GetRawButton(6) ;
//	counterclockwise = secondstick->GetRawButton(4);
	off = secondstick->GetRawButton(2);


//	switch(runwheels){
//	case 0 :
//		RUNNING
//		break;
//	case 90 :
//
//		break;
//	case 180:
//
//		break;
//	case 270 :
//
//		break;
//	case -1:
//
//		break;
//	default:
//
//
//	}


// if(runwheels == 1){
//	 RUNNING = 5;
//	 buttonpress += 1;
// }
//
// if(reversewheel == 1){
//	 RUNNING = 3;
//	 buttonpress += 1;
// }
// if(clockwise == 1){
//	 RUNNING = 6;
//	 buttonpress += 1;
// }
//
// if(counterclockwise == 1){
//	 RUNNING = 4;
//	 buttonpress += 1;
// }
// if(off==1){
//	 RUNNING = 0;
//	 buttonpress += 1;
// }
//
//if(buttonpress > 1){
//	RUNNING = 0;
//}


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
//buttonpress = 0;
//SmartDashboard::GetData(RUNNING);




//partiallyopenbutton = padone->GetRawButton(9);
//centeredbutton = padone->GetRawButton(10);
//partiallyclosedbutton = padone->GetRawButton(11);

//outmovebutton = padone->GetRawButton(12);
//inmovebutton = padone->GetRawButton(13);
outmovebutton = secondstick->GetRawButton(5);
inmovebutton = secondstick->GetRawButton(6);
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


if(outmovebutton == 1 && (partiallyclosedbutton+centeredbutton+partiallyopenbutton)< 1){
	arms.Set(armspower);

}else if(inmovebutton == 1 && (partiallyclosedbutton+centeredbutton+partiallyopenbutton)< 1){
	arms.Set(-armspower);
}
else{arms.Set(0);}




}






