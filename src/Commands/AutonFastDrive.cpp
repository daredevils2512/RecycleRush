#include <cmath>
#include "AutonFastDrive.h"
#include "../Robot.h"

AutonFastDrive::AutonFastDrive(float right, float left, int duration)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain);

	this->right = right;
	this->left = left;
	this->duration = duration;
}

// Called just before this Command runs the first time
void AutonFastDrive::Initialize()
{
	Robot::drivetrain->rearRight->Reset();
}

// Called repeatedly when this Command is scheduled to run
void AutonFastDrive::Execute()
{
	Robot::drivetrain->Go(right, left);
}

// Make this return true when this Command no longer needs to run execute()
bool AutonFastDrive::IsFinished()
{
	if(abs(Robot::drivetrain->rearRight->GetRaw()) >= duration) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void AutonFastDrive::End()
{
	Robot::drivetrain->Go(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonFastDrive::Interrupted()
{

}
