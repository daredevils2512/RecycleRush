#include "ReverseActuateIntake.h"
#include "../Robot.h"

ReverseActuateIntake::ReverseActuateIntake()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ReverseActuateIntake::Initialize()
{
	if(Robot::intakeSystem->doubleSolenoid1->Get() == DoubleSolenoid::kForward) {
		value = true;
	} else {
		value = false;
	}

}

// Called repeatedly when this Command is scheduled to run
void ReverseActuateIntake::Execute()
{
	Robot::intakeSystem->ActuateIntake(value);
}

// Make this return true when this Command no longer needs to run execute()
bool ReverseActuateIntake::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ReverseActuateIntake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseActuateIntake::Interrupted()
{

}
