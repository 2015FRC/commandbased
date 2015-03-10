/*
 * lifter.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: ausin
 */

#include "lifter.h"
#include "../RobotMap.h"

Lifter::Lifter():
		Subsystem("Lifter"),
	allbuttons(0),
	hookbottome(5),
	hookmiddle(6),
	hookgarbage(7),
	hookspeed(1),
//homebottom(0),
//homemiddle(1),
//topbottom(2),
//homegarbage(3),
//topmiddle(4),
//topgarbage(5)
liftbottom(0),
lowerbottom(0),
liftmiddle(0),
lowermiddle(0),
liftgarbage(0),
lowergarbage(0),
liftall(0),
lowerall(0),
off(0)


{

}

void Lifter::lift(Joystick* stick,Joystick* padone,Joystick * secondstick)
{
//bool up = stick->GetRawButton(7);
//bool down = stick->GetRawButton(8);
//bool alldown = stick->GetRawButton(9);



//	 liftbottom = padone->GetRawButton(1);
//	 lowerbottom = padone ->GetRawButton(2);
//	 liftmiddle = padone->GetRawButton(3);
//	 lowermiddle = padone->GetRawButton(4);
//	 liftgarbage = padone->GetRawButton(5);
//	 lowergarbage = padone->GetRawButton(6);
		liftbottom = stick->GetRawButton(8);
		 lowerbottom = stick ->GetRawButton(7);
		 liftmiddle = stick->GetRawButton(10);
		 lowermiddle = stick->GetRawButton(9);
		 liftgarbage = stick->GetRawButton(12);
		 lowergarbage = stick->GetRawButton(11);
	 liftall = secondstick->GetRawButton(12);
	 lowerall = secondstick->GetRawButton(11);
	 off = secondstick->GetRawButton(10);


//	liftbottom = secondstick->GetRawButton(8);
//	 lowerbottom = secondstick ->GetRawButton(7);
//	 liftmiddle = secondstick->GetRawButton(10);
//	 lowermiddle = secondstick->GetRawButton(9);
//	 liftgarbage = secondstick->GetRawButton(12);
//	 lowergarbage = secondstick->GetRawButton(11);
// liftall = secondstick->GetRawButton(5);
// lowerall = secondstick->GetRawButton(3);


// off = secondstick->GetRawButton(10);
SmartDashboard::PutBoolean("homegarbage",homegarbage);
SmartDashboard::PutBoolean("homemiddle",homemiddle);
SmartDashboard::PutBoolean("homebottom",homebottom);
SmartDashboard::PutBoolean("topgarbage",topgarbage);
SmartDashboard::PutBoolean("topmiddle",topmiddle);
SmartDashboard::PutBoolean("topbottom",topbottom);

if(liftbottom == 1){
	allbuttons = 0;
}

if(lowerbottom == 1){
	allbuttons = 1;
}

if(liftmiddle == 1){
	allbuttons = 2;
}

if(lowermiddle == 1){
	allbuttons = 3;
}

if(liftgarbage == 1){
	allbuttons = 4;
}

if(lowergarbage == 1){
	allbuttons = 5;
}

if(liftall == 1){
	allbuttons = 6;
	}

if(lowerall == 1){
	allbuttons = 7;
	}

if(off == 1){
allbuttons = 10;
}

switch(allbuttons){
	case 0 :
		hookbottome.Set(hookspeed);
		hookmiddle.Set(0);
		hookgarbage.Set(0);
	break;

	case 1:
		hookbottome.Set(-hookspeed);
		hookmiddle.Set(0);
		hookgarbage.Set(0);
	break;

	case 2:
		hookbottome.Set(0);
		hookmiddle.Set(hookspeed);
		hookgarbage.Set(0);
	break;

	case 3:
		hookbottome.Set(0);
		hookmiddle.Set(-hookspeed);
		hookgarbage.Set(0);
	break;

	case 4:
		hookbottome.Set(0);
		hookmiddle.Set(0);
		hookgarbage.Set(hookspeed);
	break;

	case 5:
		hookbottome.Set(0);
		hookmiddle.Set(0);
		hookgarbage.Set(-hookspeed);
	break;

	case 6:
//			if(topgarbage == 0){
//				hookgarbage.Set(hookspeed);
//			}else{
//				hookgarbage.Set(0.0);
//			}
//			if(topmiddle == 0){
//				hookmiddle.Set(hookspeed);
//			}else{
//				hookmiddle.Set(0.0);
//			}
//			if(topbottom == 0){
//				hookbottome.Set(hookspeed);
//			}else{
//				hookbottome.Set(0.0);
//			}
		hookbottome.Set(hookspeed);
		hookmiddle.Set(hookspeed);
		hookgarbage.Set(hookspeed);
	break;

	case 7:
//		if(homegarbage == 0){
//				hookgarbage.Set(-hookspeed);
//			}else{
//				hookgarbage.Set(0.0);
//			}
//
//			if(homemiddle == 0){
//				hookmiddle.Set(-hookspeed);
//			}else{
//				hookmiddle.Set(0.0);
//			}
//
//			if(homebottom == 0){
//				hookbottome.Set(-hookspeed);
//			}else{
//				hookbottome.Set(0.0);
//			}
		hookbottome.Set(-hookspeed);
		hookmiddle.Set(-hookspeed);
		hookgarbage.Set(-hookspeed);
	break;
	case 10:
		hookbottome.Set(0);
		hookmiddle.Set(0);
		hookgarbage.Set(0);
break;
default :
	hookbottome.Set(0);
	hookmiddle.Set(0);
	hookgarbage.Set(0);
break;
}
allbuttons = 12;
///////end of code loop

}





