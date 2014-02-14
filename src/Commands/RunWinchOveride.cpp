#include "RunWinchOveride.h"
#include "../Robot.h"


RunWinchOveride::RunWinchOveride(int winchNumber, float speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->speed = speed;
	this->winchNumber = winchNumber;
}

// Called just before this Command runs the first time
void RunWinchOveride::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RunWinchOveride::Execute()
{
	Robot::containerWinch->SetWinch(winchNumber, speed);
}

// Make this return true when this Command no longer needs to run execute()
bool RunWinchOveride::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RunWinchOveride::End()
{
	Robot::containerWinch->SetWinch(winchNumber, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunWinchOveride::Interrupted()
{
	Robot::containerWinch->SetWinch(winchNumber, 0);
}
