#include "SetServos.h"
#include "../Robot.h"

SetServos::SetServos(bool out)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->out = out;
}

// Called just before this Command runs the first time
void SetServos::Initialize()
{
	Robot::servoSet = out;
	Robot::servosMove = true;
}

// Called repeatedly when this Command is scheduled to run
void SetServos::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetServos::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetServos::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetServos::Interrupted()
{

}
