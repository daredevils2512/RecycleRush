#include "GoToLevel.h"

GoToLevel::GoToLevel(int _level) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::clawPID);
	level = _level;
}

// Called just before this Command runs the first time
void GoToLevel::Initialize() {
	Robot::clawPID->Enable();
	if(level >= 0 && level < 7) {
		Robot::clawPID->SetSetpoint(Robot::clawPID->LEVELHEIGHT[level]);
	} else {
		Robot::clawPID->Disable();
	}
}

// Called repeatedly when this Command is scheduled to run
void GoToLevel::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool GoToLevel::IsFinished() {
	return Robot::clawPID->OnTarget();
}

// Called once after isFinished returns true
void GoToLevel::End() {
	Robot::clawPID->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoToLevel::Interrupted() {

}
