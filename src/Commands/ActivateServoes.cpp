#include "ActivateServoes.h"
#include "../Robot.h"

ActivateServoes::ActivateServoes()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->out = out;
}

// Called just before this Command runs the first time
void ActivateServoes::Initialize()
{
////	if (Robot::containerGrabber->GetServosOut()) {
//		Robot::containerGrabber->SetServos(false);
////	} else {
////		Robot::containerGrabber->SetServos(true);
////	}
}

// Called repeatedly when this Command is scheduled to run
void ActivateServoes::Execute()
{
//	//	if (Robot::containerGrabber->GetServosOut()) {
//			Robot::containerGrabber->SetServos(false);
//	//	} else {
//	//		Robot::containerGrabber->SetServos(true);
//	//	}
}

// Make this return true when this Command no longer needs to run execute()
bool ActivateServoes::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ActivateServoes::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActivateServoes::Interrupted()
{

}
