// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


//#include <cmath>
#include "ClawPID.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Robot.h"

const float ClawPID::LEVELHEIGHT[] = {0, -135, -195, -300, -408, -513, -619, -615};
//-195
//const std::vector<int> ClawPID::LEVELHEIGHT = {0, -53, -195, -300, -408, -513, -619, -670};
//Delta Place = 58;
const float ClawPID::PLACEOFFSET = 58;
const float ClawPID::MINSETPOINT = 0;

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
ClawPID::ClawPID() : PIDSubsystem("ClawPID", 0.3, 0.0003, -0.2) {
	SetAbsoluteTolerance(4.0);
	GetPIDController()->SetContinuous(false);
	LiveWindow::GetInstance()->AddActuator("ClawPID", "PIDSubsystem Controller", GetPIDController());
	GetPIDController()->SetOutputRange(-1.0, 1.0);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	bottom = RobotMap::clawPIDBottom;
	top = RobotMap::clawPIDTop;
	heightEnccoder = RobotMap::clawPIDHeightEnccoder;

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
	if((bottom->Get() == false || (output < 0 && Robot::intakeSystem->doubleSolenoid1->Get() == DoubleSolenoid::kForward)) && ((top->Get() == false || Robot::oi->getJoystick2()->GetRawButton(7) == true) || output > 0)) {
		float motorSetting;
		if(output > 0) {
			if(output >= 0.1) {
				motorSetting = output;
			} else {
				motorSetting = 0.1;
			}
		} else if (output < 0) {
			if(output <= -0.1) {
				motorSetting = output;
			} else {
				motorSetting = -0.1;
			}
		} else {
			motorSetting = 0;
		}
		clawMotor->PIDWrite(-motorSetting);
		clawMotor2->PIDWrite(motorSetting);
	} else {
		clawMotor->Set(0);
		clawMotor2->Set(0);
	}
}

void ClawPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void ClawPID::SetMotor(float velocity) {
	if(bottom->Get() == false && ((top->Get() == false || Robot::oi->getJoystick2()->GetRawButton(7) == true) || velocity < 0)) {
//		if(heightEnccoder->GetRaw() >= -2 && Robot::intakeSystem->doubleSolenoid1->Get() == DoubleSolenoid::kReverse) {
			clawMotor->Set(velocity);
			clawMotor2->Set(-velocity);
//		} else {
//			clawMotor->Set(0);
//			clawMotor2->Set(0);
//		}
	} else {
		if((velocity > 0 && Robot::intakeSystem->doubleSolenoid1->Get() == DoubleSolenoid::kForward) && ((top->Get() == false || Robot::oi->getJoystick2()->GetRawButton(7) == true) || velocity < 0)) {
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
