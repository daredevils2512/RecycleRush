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
#include "Commands/AutonomousCommand.h"
#include "Commands/AutonomousForward.h"
#include "Commands/DriveRobot.h"
#include "Commands/GoToLevel.h"
#include "Commands/RunIntake.h"
#include "Commands/RunWinch.h"
#include "Commands/StopIntake.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	joystick2 = new Joystick(1);
	
	joystick1 = new Joystick(0);
	
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("DriveRobot", new DriveRobot());

	SmartDashboard::PutData("RunIntake", new RunIntake());

	SmartDashboard::PutData("StopIntake", new StopIntake());

	SmartDashboard::PutData("Autonomous Forward", new AutonomousForward());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	SmartDashboard::PutData("Go to level 0", new GoToLevel(0, false));
	SmartDashboard::PutData("Go to level 1", new GoToLevel(1, false));
	SmartDashboard::PutData("Go to level 2", new GoToLevel(2, false));
	SmartDashboard::PutData("Go to level 3", new GoToLevel(3, false));
	SmartDashboard::PutData("Go to level 4", new GoToLevel(4, false));
	SmartDashboard::PutData("Go to level 5", new GoToLevel(5, false));
	SmartDashboard::PutData("Go to level 6", new GoToLevel(6, false));

	SmartDashboard::PutData("Run Winch 1", new RunWinch(1));
	SmartDashboard::PutData("Run Winch 2", new RunWinch(2));
	SmartDashboard::PutData("Run Winch 3", new RunWinch(3));

	//Experimental output of PID controller to SmartDashboard for tuning
	SmartDashboard::PutData("Claw PID", Robot::clawPID->RetrivePIDController());

	SmartDashboard::PutNumber("PID Encoder", Robot::clawPID->heightEnccoder->Get());


//	LiveWindow::GetInstance()->AddActuator("ClawPID", "Claw PID Controller", Robot::clawPID->RetrivePIDController());
//	LiveWindow::GetInstance()->AddActuator("ClawPID", "clawMotor", Robot::clawPID->clawMotor);
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getJoystick2() {
	return joystick2;
}

Joystick* OI::getJoystick1() {
	return joystick1;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

float OI::GetX() {
	return joystick1->GetRawAxis(1);
}

float OI::GetY() {
	return joystick1->GetRawAxis(2);
}

float OI::GetR() {
	return joystick1->GetTwist();
}

