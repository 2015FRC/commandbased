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
		Subsystem("Chassis")
{
Rightfront = new Talon(0);
Rightrear = new Talon(1);
Leftfront = new Talon(2);
Leftrear = new Talon(3);

}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	std::cout << "Setting default command";
	//SetDefaultCommand(new DriveCommand());
}

void Chassis::update(Joystick* stick,Joystick* padone)
{
	float x = stick->GetX();
	float y = stick->GetY();
	float z = stick->GetZ();
	float power = stick->GetThrottle();

	x = x * abs(x);
	y = y * abs(y);
	z = z * abs(z)/2;

	if (abs(z) < 0.1) {
				z = 0;
			} //Adds dead zone to rotation values

	DriveToggle = 0;

			if(DriveToggle == 0) {



	float FR = (x+y+z) * power;
	float RR = (-x+y+z) * power;
	float FL = (x-y+z) * power;
	float BL = (-x-y+z) * power;

//	Motor[Drive::RightFront].Set(FR);
//	Motor[Drive::RightRear].Set(RR);
//	Motor[Drive::LeftFront].Set(FL);
//	Motor[Drive::LeftRear].Set(BL);


			}else{
////////////////////elative staeraing code///////////////////////////
/*				double	x = x(sin(x(3.14/180))+cos(y(3.14/180)));
				double	y = y(sin(y(3.14/180))-cos(x(3.14/180)));

				float FR = (x+y+z) * power;
				float RR = (-x+y+z) * power;
				float FL = (x-y+z) * power;
				float BL = (-x-y+z) * power;

				Motor[Drive::RightFront].Set(FR);
				Motor[Drive::RightRear].Set(RR);
				Motor[Drive::LeftFront].Set(FL);
				Motor[Drive::LeftRear].Set(BL);
*/
			}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.




