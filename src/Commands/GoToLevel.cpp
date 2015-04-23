#include <cmath>
#include "GoToLevel.h"

GoToLevel::GoToLevel(int level) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::clawPID);

	this->level = level;
	goingDown = false;
}

// Called just before this Command runs the first time
void GoToLevel::Initialize() {
	Robot::clawPID->Enable();
	if(level >= 0 && level < 8) {
		Robot::lEDindicator->TurnLEDoff();
		Robot::clawPID->SetSetpoint(Robot::clawPID->LEVELHEIGHT[level]);
		if(level == 1) {
			Robot::intakeSystem->SetCooperatition(true);
		}
		if (level == 7) {
			Robot::servoSet = true;
		}
	} else {
		Robot::clawPID->Disable();
	}
	if(Robot::clawPID->LEVELHEIGHT[level] > Robot::clawPID->heightEnccoder->GetRaw()) {
		//Down
		goingDown = true;
//		35:1 0.3, 0.0003, -0.2 Mk. 2 0.025
//		50:1 0.4, 0.0003, -0.2


		Robot::clawPID->RetrivePIDController()->SetPID(0.025, 0.0, 0.0);
	} else {
//		35:1, 0.03, 0.0003, 0.0 Mk2 0.02 0.0005
//		50:1, 0.02, 0.0003, 0.0

		Robot::clawPID->RetrivePIDController()->SetPID(0.02, 0.0005, 0.0);

	}
}

// Called repeatedly when this Command is scheduled to run
void GoToLevel::Execute() {
//	if(goingDown) {
//		if(Robot::clawPID->heightEnccoder->GetRaw())
//		Robot::clawPID->SetMotor(1.5 * TimeSinceInitialized() + 0.15);
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool GoToLevel::IsFinished() {
	return Robot::clawPID->OnTarget();
}

// Called once after isFinished returns true
void GoToLevel::End() {
	Robot::clawPID->Disable();
	Robot::clawPID->SetMotor(0);

	Robot::servoSet = false;

	Robot::lEDindicator->TurnLEDon();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoToLevel::Interrupted() {
	Robot::clawPID->Disable();
	Robot::clawPID->SetMotor(0);
}
