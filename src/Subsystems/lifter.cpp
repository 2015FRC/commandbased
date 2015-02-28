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
	hookbottome(5),
	hookmiddle(6),
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



if(liftbottom == 1 ){
	hookmiddle.Set(0);
	hookgarbage.Set(0);
	if(topbottom == 0){
		hookbottome.Set(hookspeed);
	}else{
		hookbottome.Set(0);
	}
} else if(lowerbottom == 1){
	hookmiddle.Set(0);
	hookgarbage.Set(0);
	if ( homebottom == 0){
		hookbottome.Set(-hookspeed);
	}else{
		hookbottome.Set(0);
	}
} else if(liftmiddle){
		hookbottome.Set(0);
		hookgarbage.Set(0);
	if(topmiddle == 0){
		hookmiddle.Set(hookspeed);
	}else{
		hookmiddle.Set(0);
	}
}else if(lowermiddle == 1){
		hookbottome.Set(0);
		hookgarbage.Set(0);
	if(homemiddle == 0){
		hookmiddle.Set(-hookspeed);
	}else{
		hookmiddle.Set(0);
	}
}else if(liftgarbage == 1 ){
		hookbottome.Set(0);
		hookmiddle.Set(0);
	if(topgarbage == 0){
		hookgarbage.Set(hookspeed);
	}else{
		hookgarbage.Set(0);
	}
}else if(lowergarbage == 1 ){
		hookbottome.Set(0.0);
		hookmiddle.Set(0.0);
	if(homegarbage == 0){
		hookgarbage.Set(-hookspeed);
	}else{
		hookgarbage.Set(0.0);
	}
}else if(liftall == 1){
	if(topgarbage == 0){
		hookgarbage.Set(hookspeed);
	}else{
		hookgarbage.Set(0.0);
	};
	if(topmiddle == 0){
		hookmiddle.Set(hookspeed);
	}else{
		hookmiddle.Set(0.0);
	}
	if(topbottom == 0){
		hookbottome.Set(hookspeed);
	}else{
		hookbottome.Set(0.0);
	}

}else if(lowerall == 1){
	if(homegarbage == 0){
		hookgarbage.Set(-hookspeed);
	}else{
		hookgarbage.Set(0.0);
	};

	if(homemiddle == 0){
		hookmiddle.Set(-hookspeed);
	}else{
		hookmiddle.Set(0.0);
	}

	if(homebottom == 0){
		hookbottome.Set(-hookspeed);
	}else{
		hookbottome.Set(0.0);
	}

}else{
	hookbottome.Set(0);
	hookmiddle.Set(0);
	hookgarbage.Set(0);
}

///////end of code loop

}





