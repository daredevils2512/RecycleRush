#include "SetIntake.h"

SetIntake::SetIntake(float left, float right)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intakeSystem);
	this->left = left;
	this->right = right;
}

// Called just before this Command runs the first time
void SetIntake::Initialize()
{
	Robot::intakeSystem->SetIntakeMotors(left, right);
}

// Called repeatedly when this Command is scheduled to run
void SetIntake::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetIntake::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetIntake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetIntake::Interrupted()
{

}
