#include "AutonDrive.h"

AutonDrive::AutonDrive(float right, float left, int duration)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain);

	this->right = right;
	this->left = left;
	this->duration = duration;
}

// Called just before this Command runs the first time
void AutonDrive::Initialize()
{
	Robot::drivetrain->rearRight->Reset();
}

// Called repeatedly when this Command is scheduled to run
void AutonDrive::Execute()
{
	if (TimeSinceInitialized() < 0.25) {
		Robot::drivetrain->Go(0.3 * right, 0.3 * left);
	} else if (TimeSinceInitialized() < 0.5) {
		Robot::drivetrain->Go(0.6 * right, 0.6 * left);
	} else {
		Robot::drivetrain->Go(right, left);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonDrive::IsFinished()
{
	if(Robot::drivetrain->rearRight->GetRaw() <= duration) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void AutonDrive::End()
{
	Robot::drivetrain->Go(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDrive::Interrupted()
{

}
