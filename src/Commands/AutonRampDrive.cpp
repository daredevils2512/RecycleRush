#include "AutonRampDrive.h"
#include "../Robot.h"

AutonRampDrive::AutonRampDrive(float right, float left, float distance, float startRight, float startLeft, bool rampDown, float rampRate)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain);

	this->left = left;
	this->right = right;
	this->distance = distance;
	this->startLeft = startLeft;
	this->startRight = startRight;
	this->rampDown = rampDown;
	this->rampRate = rampRate;
	lastTime = 0;
}

// Called just before this Command runs the first time
void AutonRampDrive::Initialize()
{
	Robot::drivetrain->rearRight->Reset();
	Robot::drivetrain->Go(startRight, startLeft);
}

// Called repeatedly when this Command is scheduled to run
void AutonRampDrive::Execute()
{
	if (abs(Robot::drivetrain->rearRight->GetRaw()) <= distance * (4 / 5) || !rampDown) {
		Robot::drivetrain->Go(std::fmin(right, startRight + (TimeSinceInitialized() * rampRate)), std::fmin(left, startLeft + (TimeSinceInitialized() * rampRate)));
		lastTime = TimeSinceInitialized();
	} else {
		Robot::drivetrain->Go(std::fmax(0.1, right - (TimeSinceInitialized() * rampRate)), std::fmax(0.1, left - (TimeSinceInitialized() * rampRate)));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonRampDrive::IsFinished()
{
	return (abs(Robot::drivetrain->rearRight->GetRaw()) >= distance);
}

// Called once after isFinished returns true
void AutonRampDrive::End()
{
	Robot::drivetrain->Go(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonRampDrive::Interrupted()
{
	End();
}
