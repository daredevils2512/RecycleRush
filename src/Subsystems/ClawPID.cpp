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

const float ClawPID::LEVELHEIGHT[] = {0, 10, 20, 30, 40, 50, 60};
const float ClawPID::PLACEOFFSET = 5;
const float ClawPID::MINSETPOINT = 0;

ClawPID::ClawPID() : PIDSubsystem("ClawPID", 1.0, 0.0, 0.0) {
	SetAbsoluteTolerance(0.2);
	GetPIDController()->SetContinuous(false);
	LiveWindow::GetInstance()->AddActuator("ClawPID", "PIDSubsystem Controller", GetPIDController());
	GetPIDController()->SetOutputRange(-1.0, 1.0);

	heightEnccoder = RobotMap::clawPIDHeightEnccoder;

	clawMotor = RobotMap::clawPIDClawMotor;

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
    return heightEnccoder->PIDGet();
}

void ClawPID::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	clawMotor->PIDWrite(output);
}

void ClawPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

void ClawPID::SetMotor(float velocity) {
	clawMotor->Set(velocity);
}

PIDController* ClawPID::RetrivePIDController() {
	return GetPIDController();
}
