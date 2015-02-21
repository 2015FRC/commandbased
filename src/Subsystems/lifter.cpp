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
	hookone(5),
	hooktwo(6),
	hookgarbage(7)
//homebottom(0),
//homemiddle(1),
//topbottom(2),
//homegarbage(3),
//topmiddle(4),
//topgarbage(5)

{

}

void Lifter::lift(Joystick* stick,Joystick* padone)
{
//bool up = stick->GetRawButton(7);
//bool down = stick->GetRawButton(8);
//bool alldown = stick->GetRawButton(9);

	hookspeed = padone->GetThrottle();

	 liftbottom = padone->GetRawButton(0);
	 lowerbottom = padone ->GetRawButton(1);
	 liftmiddle = padone->GetRawButton(2);
	 lowermiddle = padone->GetRawButton(3);
	 liftgarbage = padone->GetRawButton(4);
	 lowergarbage = padone->GetRawButton(5);
	 liftall = padone->GetRawButton(6);
	 lowerall = padone->GetRawButton(7);



if(liftbottom == 1 && topmiddle == 0){
	hooktwo.Set(hookspeed);
}else{
	hooktwo.Set(0);	}
if(lowerbottom == 1 && homebottom == 0){
		hookone.Set(-hookspeed);
	}else{
		hookone.Set(0);}


if(liftmiddle == 1 && topmiddle == 0){
		hooktwo.Set(hookspeed);
	}else{
		hooktwo.Set(0);	}
if(lowermiddle == 1 && homemiddle == 0){
		hooktwo.Set(-hookspeed);
	}else{
		hooktwo.Set(0);}


if(liftgarbage == 1 && topgarbage == 0){
		hookgarbage.Set(hookspeed);
	}else{
		hookgarbage.Set(0);	}
if(lowerbottom == 1 && homegarbage == 0){
		hookgarbage.Set(-hookspeed);
	}else{
		hookgarbage.Set(0);}



if(liftall == 1){
			if(topgarbage == 0){
				hookgarbage.Set(hookspeed);
			}else{
				hookgarbage.Set(0);
			};

			if(topmiddle == 0){
				hooktwo.Set(hookspeed);
			}else{
				hooktwo.Set(0);
			}

			if(topmiddle == 0){
				hooktwo.Set(hookspeed);
			}else{
				hooktwo.Set(0);
			}

	}else{

		if(homegarbage == 0){
			hookgarbage.Set(-hookspeed);
		}else{
			hookgarbage.Set(0);
		};

		if(homemiddle == 0){
			hooktwo.Set(-hookspeed);
		}else{
			hooktwo.Set(0);
		}

		if(homemiddle == 0){
			hooktwo.Set(-hookspeed);
		}else{
			hooktwo.Set(0);
		}







}

	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.




