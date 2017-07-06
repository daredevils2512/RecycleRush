// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "IntakeSystem.h"
#include "../RobotMap.h"
#include "../Commands/CheckIntake.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

IntakeSystem::IntakeSystem() : Subsystem("IntakeSystem") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftIntake = RobotMap::intakeSystemLeftIntake;
	rightIntake = RobotMap::intakeSystemRightIntake;
	doubleSolenoid1 = RobotMap::intakeSystemDoubleSolenoid1;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	cooperatition = false;
}
    
void IntakeSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new CheckIntake());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeSystem::SetIntakeMotors(float leftVelocity, float rightVelocity) {
	leftIntake->Set(leftVelocity);
	rightIntake->Set(rightVelocity);
}

bool IntakeSystem::GetCooperatition() {
	return cooperatition;
}

void IntakeSystem::ActuateIntake(bool on) {
	if(on) {
		doubleSolenoid1->Set(frc::DoubleSolenoid::kReverse);
//		solenoid1->Set(true);
//		solenoid2->Set(false);
	} else {
		doubleSolenoid1->Set(frc::DoubleSolenoid::kForward);
//		solenoid1->Set(true);
//		solenoid2->Set(true);
	}
}

void IntakeSystem::SetCooperatition(bool coop) {
	cooperatition = coop;
}
