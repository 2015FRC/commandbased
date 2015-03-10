/*
 * chassis.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: ausin
 */

#include "chassis.h"
#include "../RobotMap.h"
#include "math.h"


Chassis::Chassis() :
		Subsystem("Chassis"),
		pdp(),
Rightfront(0),
Rightrear(1),
Leftfront(2),
Leftrear(3),
autoTimer(),
passedtime(0.0),
autostate(Initial),
x(0.0),
y(0.0),
z(0.0),
rawpower(0.0),
power(0.0),
FR(0.0),
RR(0.0),
FL(0.0),
BL(0.0),
timestart(0.0),
override(0)
{


}

void Chassis::InitDefaultCommand()
{


	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	std::cout << "Setting default command";
	//SetDefaultCommand(new DriveCommand());
}

void Chassis::update(Joystick* stick,Joystick* padone,Joystick* secondstick)
{/////////////reads joystick values
	 x = stick->GetX();
	 y = stick->GetY();
	 z = stick->GetZ();

//	 x = .25;
//	 y = 0;
//	 z = 0;


	rawpower = stick->GetThrottle();
////////////////////creates dead zones on joysticks
////	x=x;
////	y=y;
////	z=z;
////power=power;
//	//DriveToggle = 0;
//	////////////////////relative staeraing code///////////////////////////
//	/*
//	 * if(DriveToggle == 1){
//
//	 * 					x = x(sin(x(3.14/180))+cos(y(3.14/180)));
//						y = y(sin(y(3.14/180))-cos(x(3.14/180)));
//
//					 FR = (x+y+z) * power;
//					 RR = (-x+y+z) * power;
//					 FL = (x-y+z) * power;
//					 BL = (-x-y+z) * power;
//
//					 setmotorsfromjoystick(x,y,z,power);
//}else{
//	*/
//
//}else{
//
//x=0;
//y=0;
//z=0;
//rawpower =0;
//	//DriveToggle = 0;
//	////////////////////relative staeraing code///////////////////////////
//	/*				double	x = x(sin(x(3.14/180))+cos(y(3.14/180)));
//					double	y = y(sin(y(3.14/180))-cos(x(3.14/180)));
//
//					 FR = (x+y+z) * power;
//					 RR = (-x+y+z) * power;
//					 FL = (x-y+z) * power;
//					 BL = (-x-y+z) * power;
//
//					Motor[Drive::RightFront].Set(FR);
//					Motor[Drive::RightRear].Set(RR);
//					Motor[Drive::LeftFront].Set(FL);
//					Motor[Drive::LeftRear].Set(BL);
//	*/
//
//
//}

//x=x+xo;
//y=y+yo;
//z=z+zo;
//power=1;
//SmartDashboard::PutString("drive",x,y,z,power,override);
	setmotorsfromjoystick(x,y,z,rawpower);
	SmartDashboard::PutNumber("currentrf", pdp.GetCurrent(12));
	SmartDashboard::PutNumber("currentrr", pdp.GetCurrent(13));
	SmartDashboard::PutNumber("currentlf", pdp.GetCurrent(14));
	SmartDashboard::PutNumber("currentlr", pdp.GetCurrent(15));
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::autoupdate(Joystick* padone){


	double teststate = SmartDashboard::GetNumber("teststate", 0);
	SmartDashboard::PutNumber("teststate", teststate);
//	SmartDashboard::PutNumber("testtwo", teststate);
	//autostate = teststate;
	if(teststate == 0){
		autostate = Initial;
	}else if(teststate == 1){
		autostate = Movingforward;
	}else{
		autostate = Stopmoving;

	}
	//SmartDashboard::GetNumber("state",&autostate);
	SmartDashboard::PutNumber("state",autostate);
	//SmartDashboard::GetNumber("autostate",autostate);

	static int iteration(0);
	iteration ++ ;
	SmartDashboard::PutNumber("loops", iteration);
	//SmartDashboard::PutNumber("state",autostate);
	//SmartDashboard::PutNumber("time1", autoTimer.Get());
	//SmartDashboard::PutNumber("autostate",autostate);
	switch(autostate){
	case Initial:
		SmartDashboard::PutNumber("state",autostate);
		autoTimer.Reset();
		autoTimer.Start();
		//SmartDashboard::PutNumber("timefirstreset", autoTimer.Get());
		autostate = Movingforward;
		teststate = 1;
		SmartDashboard::PutNumber("teststate", teststate);
		SmartDashboard::PutString("changestate","from initial to moving forward");
		break;
	case Movingforward :
		SmartDashboard::PutNumber("state",autostate);
		if(autoTimer.HasPeriodPassed(2.0)){
			autostate = Stopmoving;
			teststate = 2;
			SmartDashboard::PutNumber("teststate", teststate);
			autoTimer.Reset();
			SmartDashboard::PutString("changestate","from movingforawrd to stopmoving");
		}else{
			//SmartDashboard::PutNumber("autostate",autostate);
			setmotorsfromjoystick(1,0,0,1);
		}
		break;
	case Stopmoving :
		SmartDashboard::PutNumber("state",autostate);
		setmotorsfromjoystick(0,0,0,0);
		teststate = 2;
		SmartDashboard::PutNumber("teststate", teststate);
		break;
	default :
		SmartDashboard::PutNumber("errorinchassisautoupdate", autostate);
		setmotorsfromjoystick(0,0,0,0);
	}




}


void Chassis::setmotorsfromjoystick(float x,float y,float z,float power){
		x = x * abs(x);
		y = y * abs(y);
		z = z * abs(z)/2;
		power = (rawpower+1.0)/2;

		if (abs(z) > 0.05)
			{
				z = 0;
			} //Adds dead zone to rotation values


		 FR = (x+y+z) * power;
		 RR = (-x+y+z) * power;
		 FL = (x-y+z) * power;
		 BL = (-x-y+z) * power;

		Rightfront.Set(FR);
		Rightrear.Set(RR);
		Leftfront.Set(FL);
		Leftrear.Set(BL);
//			Rightfront.Set(1);
//			Rightrear.Set(0);
//			Leftfront.Set(0);
//			Leftrear.Set(0);



}


