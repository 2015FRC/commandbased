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
Rightfront(0),
Rightrear(1),
Leftfront(2),
Leftrear(3),
x(0.0),
y(0.0),
z(0.0),
DriveToggle(0),
rawpower(0.0),
power(0.0),
FR(0.0),
RR(0.0),
FL(0.0),
BL(0.0)
{


}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	std::cout << "Setting default command";
	//SetDefaultCommand(new DriveCommand());
}

void Chassis::update(Joystick* stick,Joystick* padone)
{/////////////reads joystick values
	 x = stick->GetX();
	 y = stick->GetY();
	 z = stick->GetZ();

	rawpower = stick->GetThrottle();

////////////////////creates dead zones on joysticks

	x = x * abs(x);
	y = y * abs(y);
	z = z * abs(z)/2;
	power = (rawpower+1.0)/2;

	if (abs(z) > 0.1)
		{
			z = 0;
		} //Adds dead zone to rotation values

	DriveToggle = 0;

			if(DriveToggle == 0) {

	 FR = (x+y+z) * power;
	 RR = (-x+y+z) * power;
	 FL = (x-y+z) * power;
	 BL = (-x-y+z) * power;

	Rightfront.Set(FR);
	Rightrear.Set(RR);
	Leftfront.Set(FL);
	Leftrear.Set(BL);

			}else{
////////////////////elative staeraing code///////////////////////////
/*				double	x = x(sin(x(3.14/180))+cos(y(3.14/180)));
				double	y = y(sin(y(3.14/180))-cos(x(3.14/180)));

				 FR = (x+y+z) * power;
				 RR = (-x+y+z) * power;
				 FL = (x-y+z) * power;
				 BL = (-x-y+z) * power;

				Motor[Drive::RightFront].Set(FR);
				Motor[Drive::RightRear].Set(RR);
				Motor[Drive::LeftFront].Set(FL);
				Motor[Drive::LeftRear].Set(BL);
*/
			}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.




