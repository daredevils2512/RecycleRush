// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include <cmath>
#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/ActuateIntake.h"
#include "Commands/AutonDrive.h"
#include "Commands/AutonRunIntake.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/AutonomousMainCommand.h"
#include "Commands/CheckIntake.h"
#include "Commands/ClawOveride.h"
#include "Commands/DriveRobot.h"
#include "Commands/GoToLevel.h"
#include "Commands/Place.h"
#include "Commands/ResetLevelEncoder.h"
#include "Commands/RunCompressor.h"
#include "Commands/RunIntake.h"
#include "Commands/RunWinch.h"
#include "Commands/StopClaw.h"
#include "Commands/StopIntake.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "Controller/DriverXbox.h"
#include "Controller/CodriverJoystickCustom.h"
#include "Commands/SetIntake.h"
#include "Commands/PickUp.h"
#include "Commands/DropContainers.h"
#include "Commands/RunWinchOveride.h"
#include "Commands/StationPickUp.h"
#include "Commands/GoToHeight.h"

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

	SmartDashboard::PutData("ResetLevelEncoder", new ResetLevelEncoder());

	SmartDashboard::PutData("StopClaw", new StopClaw());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	SmartDashboard::PutData("Go to level 0", new GoToLevel(0));
	SmartDashboard::PutData("Go to level 1", new GoToLevel(1));
	SmartDashboard::PutData("Go to level 2", new GoToLevel(2));
	SmartDashboard::PutData("Go to level 3", new GoToLevel(3));
	SmartDashboard::PutData("Go to level 4", new GoToLevel(4));
	SmartDashboard::PutData("Go to level 5", new GoToLevel(5));
	SmartDashboard::PutData("Go to level 6", new GoToLevel(6));

	SmartDashboard::PutData("Go Down & Reset Encoder", new ResetLevelEncoder());

	SmartDashboard::PutData("Run Winch 1", new RunWinch(1, 1.0, 0.5));
	SmartDashboard::PutData("Run Winch 2", new RunWinch(2, 1.0, 0.5));

	SmartDashboard::PutData("Run Winch 1 Reverse", new RunWinch(1, -1.0, 0.5));
	SmartDashboard::PutData("Run Winch 2 Reverse", new RunWinch(2, -1.0, 0.5));

	//Experimental output of PID controller to SmartDashboard for tuning
	SmartDashboard::PutData("Claw PID", Robot::clawPID->RetrivePIDController());

	SmartDashboard::PutData("Actuate Intake In", new ActuateIntake(true));
	SmartDashboard::PutData("Actuate Intake Out", new ActuateIntake(false));

	SmartDashboard::PutData("Run Fan", new ResetLevelEncoder());

	SmartDashboard::PutData("Run Intake", new SetIntake(0.5, 0.5));

//	LiveWindow::GetInstance()->AddActuator("ClawPID", "Claw PID Controller", Robot::clawPID->RetrivePIDController());
//	LiveWindow::GetInstance()->AddActuator("ClawPID", "clawMotor", Robot::clawPID->clawMotor);

	driverController = new DriverXbox(joystick1);
	codriverController = new CodriverJoystickCustom(joystick2, joystick3);

	tempLevel1 = new JoystickButton(joystick3, 16);
	resetButton = new JoystickButton(joystick3, 3);
	pickUp = new JoystickButton(joystick1, 1);
	dropContainers = new JoystickButton(joystick1, 8);
	center = new JoystickButton(joystick1, 6);
//	secondaryPlace = new JoystickButton(joystick2, 1);
	rightIn = new JoystickButton(joystick2, 4);
	rightOut = new JoystickButton(joystick2, 6);
	leftIn = new JoystickButton(joystick2, 3);
	leftOut = new JoystickButton(joystick2, 5);
	stationPickUp = new JoystickButton(joystick2, 1);

	resetButton->WhenPressed(new ResetLevelEncoder());
	pickUp->WhenPressed(new PickUp());
	dropContainers->WhenPressed(new DropContainers());
	center->WhenPressed(new ActuateIntake(true));
	center->WhenReleased(new ActuateIntake(false));
//	secondaryPlace->WhenPressed(new Place());
	rightIn->WhileHeld(new RunWinchOveride(1, 0.5));
	rightOut->WhileHeld(new RunWinchOveride(1, -1.0));
	leftIn->WhileHeld(new RunWinchOveride(2, 0.5));
	leftOut->WhileHeld(new RunWinchOveride(2, -1.0));
	stationPickUp->WhenPressed(new GoToLevel(0));
	stationPickUp->WhenReleased(new GoToHeight(-366));

//	driverController->GetPlaceButton()->WhenPressed(new Place());
//	driverController->GetIntakeButton()->WhenPressed(new RunIntake(1.0));
//	driverController->GetOutakeButton()->WhenPressed(new RunIntake(-1.0));
//
//	codriverController->GetCoopLevel()->WhenPressed(new GoToLevel(0));
	tempLevel1->WhenPressed(new GoToLevel(1));

//	codriverController->GetLevel1()->WhenPressed(new GoToLevel(0));
	codriverController->GetLevel2()->WhenPressed(new GoToLevel(2));
	codriverController->GetLevel3()->WhenPressed(new GoToLevel(3));
	codriverController->GetLevel4()->WhenPressed(new GoToLevel(4));
	codriverController->GetLevel5()->WhenPressed(new GoToLevel(5));
	codriverController->GetLevel6()->WhenPressed(new GoToLevel(6));
	codriverController->GetLevel7()->WhenPressed(new GoToLevel(7));
	codriverController->GetPlaceButton()->WhenPressed(new Place());
	codriverController->GetCoopLevel()->WhenPressed(new GoToLevel(1));

	clawOveridePos = new TriggerButton(joystick2, 1, 0.3);
	clawOverideNeg = new TriggerButton(joystick2, 1, -0.3);

	intake = new TriggerButton(joystick1, 3, 0.3);
	outake = new TriggerButton(joystick1, 2, 0.3);

	clawOveridePos->WhileHeld(new ClawOveride());
	clawOverideNeg->WhileHeld(new ClawOveride());

	clawOveridePos->WhenReleased(new StopClaw());
	clawOverideNeg->WhenReleased(new StopClaw());

	intake->WhenPressed(new ActuateIntake(true));
	outake->WhenPressed(new ActuateIntake(true));

	intake->WhileHeld(new RunIntake(-1.0));
	outake->WhileHeld(new RunIntake(1.0));

	intake->WhenReleased(new ActuateIntake(false));
	outake->WhenReleased(new ActuateIntake(false));

	intake->WhenReleased(new RunIntake(0.0));
	outake->WhenReleased(new RunIntake(0.0));
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
	return Desensitize(0, 0.3);
}

float OI::GetY() {
	return Desensitize(1, 0.3);
}

float OI::GetR() {
	return Desensitize(4, 0.3);
}

float OI::GetClawOveride() {
	return joystick2->GetRawAxis(1);
}


float OI::Desensitize(int axisNumber, float threshold) {
	float value = 0;
	if(fabs(joystick1->GetRawAxis(axisNumber)) > threshold) {
		if(joystick1->GetRawAxis(axisNumber) > 0) {
			value = (joystick1->GetRawAxis(axisNumber) - threshold) / (1 - threshold);
		} else {
			value = (joystick1->GetRawAxis(axisNumber) + threshold) / (1 - threshold);
		}
	}
	if(joystick1->GetRawButton(5)) {
		value = value / 2;
	}
	return value;
}

float OI::GetJoystick2POV() {
	return joystick2->GetPOV();
}
