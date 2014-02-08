#include "GoToHeight.h"
#include "../Robot.h"

GoToHeight::GoToHeight(float targetHeight)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::clawPID);
	this->targetHeight = targetHeight;
}

// Called just before this Command runs the first time
void GoToHeight::Initialize()
{
	if(targetHeight >= 0) {
		Robot::clawPID->Enable();
		Robot::clawPID->SetSetpoint(targetHeight);
	}
	if(targetHeight > Robot::clawPID->heightEnccoder->GetRaw()) {
		//Down
		goingDown = true;
		Robot::clawPID->RetrivePIDController()->SetPID(0.4, 0.0003, -0.2);
	} else {
		Robot::clawPID->RetrivePIDController()->SetPID(0.02, 0.0003, 0.0);
	}
}

// Called repeatedly when this Command is scheduled to run
void GoToHeight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool GoToHeight::IsFinished()
{
	return Robot::clawPID->OnTarget();;
}

// Called once after isFinished returns true
void GoToHeight::End()
{
	Robot::clawPID->Disable();
	Robot::clawPID->SetMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoToHeight::Interrupted()
{
	Robot::clawPID->Disable();
	Robot::clawPID->SetMotor(0);
}
