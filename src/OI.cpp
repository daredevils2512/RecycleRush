// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/ActuateLeftIntake.h"
#include "Commands/ActuateRightIntake.h"
#include "Commands/AutonDrive.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/AutonomousForward.h"
#include "Commands/AutonomousMainCommand.h"
#include "Commands/DriveRobot.h"
#include "Commands/GoToLevel.h"
#include "Commands/Place.h"
#include "Commands/RunIntake.h"
#include "Commands/RunWinch.h"
#include "Commands/StopIntake.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "Controller/DriverXbox.h"
#include "Controller/CodriverJoystickCustom.h"

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	joystick3 = new Joystick(2);
	
	joystick2 = new Joystick(1);
	
	joystick1 = new Joystick(0);
	
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("DriveRobot", new DriveRobot());

	SmartDashboard::PutData("StopIntake", new StopIntake());

	SmartDashboard::PutData("ActuateLeftIntake", new ActuateLeftIntake());

	SmartDashboard::PutData("ActuateRightIntake", new ActuateRightIntake());

	SmartDashboard::PutData("AutonomousForward", new AutonomousForward());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	SmartDashboard::PutData("Go to level 0", new GoToLevel(0));
	SmartDashboard::PutData("Go to level 1", new GoToLevel(1));
	SmartDashboard::PutData("Go to level 2", new GoToLevel(2));
	SmartDashboard::PutData("Go to level 3", new GoToLevel(3));
	SmartDashboard::PutData("Go to level 4", new GoToLevel(4));
	SmartDashboard::PutData("Go to level 5", new GoToLevel(5));
	SmartDashboard::PutData("Go to level 6", new GoToLevel(6));

	SmartDashboard::PutData("Run Winch 1", new RunWinch(1, 1.0));
	SmartDashboard::PutData("Run Winch 2", new RunWinch(2, 1.0));
	SmartDashboard::PutData("Run Winch 3", new RunWinch(3, 1.0));

	//Experimental output of PID controller to SmartDashboard for tuning
	SmartDashboard::PutData("Claw PID", Robot::clawPID->RetrivePIDController());

	SmartDashboard::PutNumber("PID Encoder", Robot::clawPID->heightEnccoder->Get());

	SmartDashboard::PutNumber("DriverX 2", GetX());
	SmartDashboard::PutNumber("DriverY 2", GetY());
	SmartDashboard::PutNumber("DriverTwist 2", GetR());

//	LiveWindow::GetInstance()->AddActuator("ClawPID", "Claw PID Controller", Robot::clawPID->RetrivePIDController());
//	LiveWindow::GetInstance()->AddActuator("ClawPID", "clawMotor", Robot::clawPID->clawMotor);

	driverController = new DriverXbox(joystick1);
	codriverController = new CodriverJoystickCustom(joystick2, joystick3);

//	driverController->GetPlaceButton()->WhenPressed(new Place());
//	driverController->GetIntakeButton()->WhenPressed(new RunIntake(1.0));
//	driverController->GetOutakeButton()->WhenPressed(new RunIntake(-1.0));
//
//	codriverController->GetCoopLevel()->WhenPressed(new GoToLevel(1));
//	codriverController->GetLevel1()->WhenPressed(new GoToLevel(1));
//	codriverController->GetLevel2()->WhenPressed(new GoToLevel(2));
//	codriverController->GetLevel3()->WhenPressed(new GoToLevel(3));
//	codriverController->GetLevel4()->WhenPressed(new GoToLevel(4));
//	codriverController->GetLevel5()->WhenPressed(new GoToLevel(5));
//	codriverController->GetLevel6()->WhenPressed(new GoToLevel(6));
//	codriverController->GetPlaceButton()->WhenPressed(new Place());
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getJoystick3() {
	return joystick3;
}

Joystick* OI::getJoystick2() {
	return joystick2;
}

Joystick* OI::getJoystick1() {
	return joystick1;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

float OI::GetX() {
	float value = 0;
	if(joystick1->GetRawAxis(0) > 0.1 || joystick1->GetRawAxis(0) < -0.1) {
		value = -joystick1->GetRawAxis(0);
	}
	return value;
//	return joystick1->GetRawAxis(0);
}

float OI::GetY() {
	float value = 0;
	if(joystick1->GetRawAxis(1) > 0.1 || joystick1->GetRawAxis(1) < -0.1) {
		value = -joystick1->GetRawAxis(1);
	}
	return value;
//	return joystick1->GetRawAxis(1);
}

float OI::GetR() {
	float value = 0;
	if(joystick1->GetRawAxis(4) > 0.1 || joystick1->GetRawAxis(4) < -0.1) {
		value = -joystick1->GetRawAxis(4);
	}
	return value;
//	return joystick1->GetRawAxis(4);
}

