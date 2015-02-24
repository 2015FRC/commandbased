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
	armspower(.6)
{


}

void Collector::collect(Joystick* stick,Joystick* padone)
{
	Relay::Value forward = (Relay::Value::kForward);
	Relay::Value reverse = (Relay::Value::kReverse);

	runwheels = stick->GetRawButton(5) ;
	reversewheel = stick->GetRawButton(3);
	clockwise = stick->GetRawButton(6) ;
	counterclockwise = stick->GetRawButton(4);
	off = stick->GetRawButton(2);



 if(runwheels == 1){
	 RUNNING = 5;
	 buttonpress += 1;
 }

 if(reversewheel == 1){
	 RUNNING = 3;
	 buttonpress += 1;
 }
 if(clockwise == 1){
	 RUNNING = 6;
	 buttonpress += 1;
 }

 if(counterclockwise == 1){
	 RUNNING = 4;
	 buttonpress += 1;
 }
 if(off==1){
	 RUNNING = 0;
	 buttonpress += 1;
 }

//if(buttonpress > 1){
//	RUNNING = 0;
//}

switch(RUNNING){
 case 3 :
	 Rightroller.Set(forward);
	 Leftroller.Set(reverse);
	 break;

 case 4:

	 Rightroller.Set(reverse);
	 Leftroller.Set(forward);
	 break;
 case 5:
	 Rightroller.Set(forward);
	 Leftroller.Set(forward);

 	 break;
 case 6:
	 Rightroller.Set(reverse);
	 Leftroller.Set(reverse);

 	 break;

 default:
	 Rightroller.Set(Relay::Value::kOff);
	 Leftroller.Set(Relay::Value::kOff);
	 }
buttonpress = 0;
//SmartDashboard::GetData(RUNNING);




partiallyopenbutton = padone->GetRawButton(9);
centeredbutton = padone->GetRawButton(10);
partiallyclosedbutton = padone->GetRawButton(11);

outmovebutton = padone->GetRawButton(12);
inmovebutton = padone->GetRawButton(13);
rawpotposition = ArmAngleSensor.GetAverageVoltage();

////////////initilize 0
if(start == 0){
	potpositionoffest = rawpotposition;
	start = 1;
}
unmapedpotposition =  rawpotposition-potpositionoffset;
potposition = unmapedpotposition/maxposition*100;


if(outmovebutton == 1 && partiallyopenbutton == 1){
	if(potposition <= partalyopenlocation){
			arms.Set(armspower);
		}else{arms.Set(0);}

}else{arms.Set(0);}

//////////////////////////////////////////////////////////////////////////
if(outmovebutton == 1 && centeredbutton == 1){
	if(potposition <= centeredlocation){
			arms.Set(armspower);
		}else{arms.Set(0);}

}else{arms.Set(0);}

////////////////////////////////////////////////////////////////////////////////////
if(outmovebutton == 1 && partiallyclosedbutton == 1){
	if(potposition <= partalyclosedlocation){
			arms.Set(armspower);
		}else{arms.Set(0);}

}else{arms.Set(0);}

////////////////////////////////////////////////////////////////////////
if(inmovebutton == 1 && partiallyopenbutton == 1){
	if(potposition >= partalyopenlocation){
			arms.Set(-armspower);
		}else{arms.Set(0);}

}else{arms.Set(0);}

/////////////////////////////////////////////
if(inmovebutton == 1 && centeredbutton == 1){
	if(potposition >= centeredlocation){
			arms.Set(-armspower);
		}else{arms.Set(0);}

}else{arms.Set(0);}
//////////////////////
if(inmovebutton == 1 && partiallyclosedbutton == 1){
	if(potposition >= partalyclosedlocation){
			arms.Set(-armspower);
		}else{arms.Set(0);}

}else{arms.Set(0);}


if(outmovebutton == 1 && (partiallyclosedbutton+centeredbutton+partiallyopenbutton)< 1){
	arms.Set(armspower);

}else if(inmovebutton == 1 && (partiallyclosedbutton+centeredbutton+partiallyopenbutton)< 1){
	arms.Set(-armspower);
}
else{arms.Set(0);}




}






