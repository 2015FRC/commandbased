/*
 * collector.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: ausin
 */
#include "Collector.h"
#include "RobotMap.h"


Collector::Collector():
		Subsystem("Collector")
{
    Rightroller = new Relay(0, Relay::Direction::kBothDirections);
    Leftroller = new Relay(1, Relay::Direction::kBothDirections);

}

void Collector::collect(Joystick* stick,Joystick* padone)
{

	bool open = stick->GetRawButton(8);
	bool close = stick->GetRawButton(7);
	Relay::Value forward = Relay::Value::kForward;
	Relay::Value reverse = Relay::Value::kReverse;
	bool runwheels = stick->GetRawButton(5) ;
	bool reversewheel = stick->GetRawButton(3);
	bool clockwise = stick->GetRawButton(6) ;
	bool counterclockwise = stick->GetRawButton(4);
	bool off = stick->GetRawButton(2);
	int buttonpress= 0;


 if(runwheels == 1){
	 RUNNING = 5;
	 buttonpress += 1;
 }

 if(reversewheel==1){
	 RUNNING = 3;
	 buttonpress += 1;
 }
 if(clockwise == 1){
	 RUNNING = 6;
	 buttonpress += 1;
 }

 if(counterclockwise==1){
	 RUNNING = 4;
	 buttonpress += 1;
 }
 if(off==1){
	 RUNNING = 0;
	 buttonpress += 1;
 }

if(buttonpress > 1){
	RUNNING = 0;
}

// switch(RUNNING){
// case 3 :
//	 relay[Collect::Rightroller].Set(forward);
//	 relay[Collect::Leftroller].Set(reverse);
//	 break;
//
// case 4:
//
//	 relay[Collect::Rightroller].Set(reverse);
//	 relay[Collect::Leftroller].Set(forward);
//	 break;
// case 5:
//	 relay[Collect::Rightroller].Set(forward);
//	 relay[Collect::Leftroller].Set(forward);
//
// 	 break;
// case 6:
//	 relay[Collect::Rightroller].Set(reverse);
//	 relay[Collect::Leftroller].Set(reverse);
//
// 	 break;
//
// default:
//	 relay[Collect::Rightroller].Set(Relay::Value::kOff);
//	 relay[Collect::Leftroller].Set(Relay::Value::kOff);
//
// }

switch(RUNNING){
 case 3 :
	 Rightroller->Set(forward);
	 Leftroller->Set(reverse);
	 break;

 case 4:

	 Rightroller->Set(reverse);
	 Leftroller->Set(forward);
	 break;
 case 5:
	 Rightroller->Set(forward);
	 Leftroller->Set(forward);

 	 break;
 case 6:
	 Rightroller->Set(reverse);
	 Leftroller->Set(reverse);

 	 break;

 default:
	 Rightroller->Set(Relay::Value::kOff);
	 Leftroller->Set(Relay::Value::kOff);



	 if(open == 1)
	 {


	 }
	 if(close == 1){

	 }

	 switch(){



	 }



 }





	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.





