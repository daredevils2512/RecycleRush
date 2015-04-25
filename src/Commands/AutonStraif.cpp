#include <cmath>
#include "AutonStraif.h"
#include "../Robot.h"

AutonStraif::AutonStraif(int duraion)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->duration = duration;
}

// Called just before this Command runs the first time
void AutonStraif::Initialize()
{
	Robot::drivetrain->rearRight->Reset();
}

// Called repeatedly when this Command is scheduled to run
void AutonStraif::Execute()
{
	Robot::drivetrain->Straif(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutonStraif::IsFinished()
{
	if(abs(Robot::drivetrain->rearRight->GetRaw()) >= duration) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void AutonStraif::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonStraif::Interrupted()
{

}
