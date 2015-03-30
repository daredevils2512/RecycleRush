#include "ActuateContainerGrabber.h"

ActuateContainerGrabber::ActuateContainerGrabber(bool actuate)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->actuate = actuate;
}

// Called just before this Command runs the first time
void ActuateContainerGrabber::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ActuateContainerGrabber::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ActuateContainerGrabber::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ActuateContainerGrabber::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActuateContainerGrabber::Interrupted()
{

}
