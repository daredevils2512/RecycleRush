#include <cmath>
#include "CodriverToteScoot.h"
#include "../Robot.h"

CodriverToteScoot::CodriverToteScoot()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intakeSystem);
}

// Called just before this Command runs the first time
void CodriverToteScoot::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CodriverToteScoot::Execute()
{
	float intake = Robot::oi->GetToteIntake();
	float turn = Robot::oi->GetToteTurn();

	if (fabs(intake) > 0.3) {
		Robot::intakeSystem->SetIntakeMotors(intake, intake);
	}
	else if (fabs(turn) > 0.3) {
		Robot::intakeSystem->SetIntakeMotors(-turn, turn);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool CodriverToteScoot::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void CodriverToteScoot::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CodriverToteScoot::Interrupted()
{
	End();
}
