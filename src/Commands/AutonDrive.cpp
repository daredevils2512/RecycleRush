#include "AutonDrive.h"

AutonDrive::AutonDrive(float magnitude, float angle, float duration)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain);

	this->magnitude = magnitude;
	this->angle = angle;
	this->duration = duration;
}

// Called just before this Command runs the first time
void AutonDrive::Initialize()
{
	SetTimeout(duration);
}

// Called repeatedly when this Command is scheduled to run
void AutonDrive::Execute()
{
	Robot::drivetrain->Go(magnitude, angle);
}

// Make this return true when this Command no longer needs to run execute()
bool AutonDrive::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutonDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDrive::Interrupted()
{

}
