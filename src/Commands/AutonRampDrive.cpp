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
}

// Called just before this Command runs the first time
void AutonRampDrive::Initialize()
{
	Robot::drivetrain->rearRight->Reset();
	Robot::drivetrain->Go(startRight, startLeft);
	rightReached = false;
	leftReached = false;
	rightSpeed = 0;
	leftSpeed = 0;
	rightDist = 0;
	leftDist = 0;
	rightTime = 0;
	leftTime = 0;
	rightFarEnough = false;
	leftFarEnough = false;
}

// Called repeatedly when this Command is scheduled to run
void AutonRampDrive::Execute() {
	if ( (!rampDown) || (!rightFarEnough)) {
		rightSpeed = std::fmin(right, startRight + (TimeSinceInitialized() * rampRate));

		if (!rightReached && rightSpeed == right) {
			rightDist = fabs(Robot::drivetrain->rearRight->GetRaw());
			rightReached = true;
		}

		if (rightReached && ((abs(Robot::drivetrain->rearRight->GetRaw()) >= distance - rightDist) || Robot::oi->getJoystick3()->GetRawButton(1))) {
			rightFarEnough = true;
			rightTime = TimeSinceInitialized();
		}
	} else {
		rightSpeed = std::fmax(0.1, right - ((TimeSinceInitialized() - rightTime) * rampRate));
	}

	if ( (!rampDown) || (!leftFarEnough)) {
		leftSpeed = std::fmin(left, startLeft + (TimeSinceInitialized() * rampRate));

		if (!leftReached && leftSpeed == left) {
			leftDist = fabs(Robot::drivetrain->rearRight->GetRaw());
			leftReached = true;
		}

		if (leftReached && ((abs(Robot::drivetrain->rearRight->GetRaw()) >= distance - leftDist) || Robot::oi->getJoystick3()->GetRawButton(1))) {
			leftFarEnough = true;
			leftTime = TimeSinceInitialized();
		}
	} else {
		leftSpeed = std::fmax(0.1, left - ((TimeSinceInitialized() - leftTime) * rampRate));
	}

	Robot::drivetrain->Go(rightSpeed, leftSpeed);

	SmartDashboard::PutNumber("Right Motor Speed (ramp)", rightSpeed);
	SmartDashboard::PutNumber("Left Motor Speed (ramp)", leftSpeed);
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
