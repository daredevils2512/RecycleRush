#include "AutonRunIntake.h"

AutonRunIntake::AutonRunIntake(float velocity, float duration)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intakeSystem);
	this->velocity = velocity;
	this->duration = duration;
}

// Called just before this Command runs the first time
void AutonRunIntake::Initialize()
{
	SetTimeout(duration);
}

// Called repeatedly when this Command is scheduled to run
void AutonRunIntake::Execute()
{
	Robot::intakeSystem->SetIntakeMotors(velocity, velocity);
}

// Make this return true when this Command no longer needs to run execute()
bool AutonRunIntake::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutonRunIntake::End()
{
	Robot::intakeSystem->SetIntakeMotors(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonRunIntake::Interrupted()
{
	Robot::intakeSystem->SetIntakeMotors(0, 0);
}
