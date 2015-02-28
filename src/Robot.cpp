#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Robot.h"



Robot::Robot():
stick(0),
secondstick(1),
padone(2),
chassis(),
_collector(),
lifter()

{

	CommandBase::init();
	autonomousCommand = new ExampleCommand();
	lw = LiveWindow::GetInstance();
}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	chassis.autoupdate(&padone);
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{


	Scheduler::GetInstance()->Run();
	chassis.update(&stick,&padone,&secondstick);
	_collector.collect(&stick,&padone,&secondstick);
	//this->_collector.collect(&stick,&padone);



}

void Robot::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Robot);

