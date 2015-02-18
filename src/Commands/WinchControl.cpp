#include "WinchControl.h"
#include "../Robot.h"

WinchControl::WinchControl()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::containerWinch);
}

// Called just before this Command runs the first time
void WinchControl::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WinchControl::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WinchControl::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WinchControl::End()
{
	Robot::containerWinch->SetWinch(1, 0.0);
	Robot::containerWinch->SetWinch(2, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchControl::Interrupted()
{
	End();
}
