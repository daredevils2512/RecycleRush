// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "ClawPID.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Robot.h"

const float ClawPID::LEVELHEIGHT[] = {0, -25, -125, -225, -325, -425, -525};
const float ClawPID::PLACEOFFSET = 5;
const float ClawPID::MINSETPOINT = 0;

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
ClawPID::ClawPID() : PIDSubsystem("ClawPID", 1.0, 0.0, 0.0) {
	SetAbsoluteTolerance(4.0);
	GetPIDController()->SetContinuous(false);
	LiveWindow::GetInstance()->AddActuator("ClawPID", "PIDSubsystem Controller", GetPIDController());
	GetPIDController()->SetOutputRange(-1.0, 1.0);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	bottom = RobotMap::clawPIDBottom;
	top = RobotMap::clawPIDTop;
	heightEnccoder = RobotMap::clawPIDHeightEnccoder;
	clawMotor = RobotMap::clawPIDClawMotor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	//Sets clawMotor to a CAN Talon in robot map as Talon srx in robot builder does not work.
	clawMotor = RobotMap::clawPIDCANTalon;

	clawMotor2 = RobotMap::clawMotor2;

	// Use these to get going:
	SetSetpoint(0); // -  Sets where the PID controller should move the system
	//                  to
	Enable(); //- Enables the PID controller.
	ITable* table = GetTable();
	ClawPID::InitTable(table);
}

double ClawPID::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;	
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
        return heightEnccoder->PIDGet();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void ClawPID::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	if(bottom->Get() == false) {
		clawMotor->PIDWrite(-output);
		clawMotor2->PIDWrite(output);
	} else {
		clawMotor->PIDWrite(0);
		clawMotor2->PIDWrite(0);
	}
}

void ClawPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void ClawPID::SetMotor(float velocity) {
	if(bottom->Get() == false) {
//		if(heightEnccoder->GetRaw() >= -2 && Robot::intakeSystem->doubleSolenoid1->Get() == DoubleSolenoid::kReverse) {
			clawMotor->Set(velocity);
			clawMotor2->Set(-velocity);
//		} else {
//			clawMotor->Set(0);
//			clawMotor2->Set(0);
//		}
	} else {
		if(velocity > 0 && Robot::intakeSystem->doubleSolenoid1->Get() == DoubleSolenoid::kForward) {
			clawMotor->Set(velocity);
			clawMotor2->Set(-velocity);
		} else {
			clawMotor->Set(0);
			clawMotor2->Set(0);
		}
	}
}

bool ClawPID::GetTop() {
	return top->Get();
}

bool ClawPID::GetBottom() {
	return bottom->Get();
}

PIDController* ClawPID::RetrivePIDController() {
	return GetPIDController();
}

void ClawPID::ResetHeightEncoder() {
	heightEnccoder->Reset();
}
