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

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
ClawPID::ClawPID() : PIDSubsystem("ClawPID", 1.0, 0.0, 0.0) {
	SetAbsoluteTolerance(0.2);
	GetPIDController()->SetContinuous(false);
	LiveWindow::GetInstance()->AddActuator("ClawPID", "PIDSubsystem Controller", GetPIDController());
	GetPIDController()->SetOutputRange(-1.0, 1.0);
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	heightEnccoder = RobotMap::clawPIDHeightEnccoder;
	clawMotor = RobotMap::clawPIDClawMotor;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	// Use these to get going:
	SetSetpoint(0); // -  Sets where the PID controller should move the system
	//                  to
	Enable(); //- Enables the PID controller.
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
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
	clawMotor->PIDWrite(output);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
}

void ClawPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
