#include "AutonWait.h"

AutonWait::AutonWait(float waitTime)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->waitTime = waitTime;
}

// Called just before this Command runs the first time
void AutonWait::Initialize()
{
	SetTimeout(waitTime);
}

// Called repeatedly when this Command is scheduled to run
void AutonWait::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutonWait::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutonWait::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonWait::Interrupted()
{

}
