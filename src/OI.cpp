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

#include "Commands/SetIntake.h"
#include "Commands/PickUp.h"
#include "Commands/DropContainers.h"
#include "Commands/RunWinchOveride.h"
#include "Commands/StationPickUp.h"
#include "Commands/GoToHeight.h"
#include "Commands/ReverseActuateIntake.h"
#include "Commands/CodriverToteScoot.h"

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

	SmartDashboard::PutData("Run Intake", new SetIntake(0.5, 0.5));

	resetButton = new JoystickButton(joystick3, resetButtonNum);
	pickUp = new JoystickButton(joystick1, pickUpNum);
	dropContainers = new JoystickButton(joystick1, dropContainersNum);
	center = new JoystickButton(joystick1, centerNum);
	rightIn = new JoystickButton(joystick2, rightInNum);
	rightOut = new JoystickButton(joystick2, rightOutNum);
	leftIn = new JoystickButton(joystick2, leftInNum);
	leftOut = new JoystickButton(joystick2, leftOutNum);
	stationPickUp = new JoystickButton(joystick2, stationPickUpNum);
	feederHeight = new JoystickButton(joystick3, feederHeightNum);

	resetButton->WhenPressed(new ResetLevelEncoder());
	pickUp->WhenPressed(new PickUp());
	dropContainers->WhenPressed(new DropContainers());

	center->WhenPressed(new ReverseActuateIntake());

	rightIn->WhileHeld(new RunWinchOveride(1, 0.5));
	rightOut->WhileHeld(new RunWinchOveride(1, -1.0));
	leftIn->WhileHeld(new RunWinchOveride(2, 0.5));
	leftOut->WhileHeld(new RunWinchOveride(2, -1.0));
	stationPickUp->WhenPressed(new GoToLevel(0));
	stationPickUp->WhenReleased(new GoToHeight(-340));

//	driverController->GetPlaceButton()->WhenPressed(new Place());

	level1 = new JoystickButton(joystick3, level1Num);
	level2 = new JoystickButton(joystick3, level2Num);
	level3 = new JoystickButton(joystick3, level3Num);
	level4 = new JoystickButton(joystick3, level4Num);
	level5 = new JoystickButton(joystick3, level5Num);
	level6 = new JoystickButton(joystick3, level6Num);
	level7 = new JoystickButton(joystick3, level7Num);
	placeButton = new JoystickButton(joystick3, placeButtonNum);
	coopLevel = new JoystickButton(joystick3, coopLevelNum);

	level2->WhenPressed(new GoToLevel(2));
	level3->WhenPressed(new GoToLevel(3));
	level4->WhenPressed(new GoToLevel(4));
	level5->WhenPressed(new GoToLevel(5));
	level6->WhenPressed(new GoToLevel(6));
	level7->WhenPressed(new GoToLevel(7));
	placeButton->WhenPressed(new Place());
	coopLevel->WhenPressed(new GoToLevel(1));

	clawOveridePos = new TriggerButton(joystick2, clawOverideNum, 0.3);
	clawOverideNeg = new TriggerButton(joystick2, clawOverideNum, -0.3);

	intake = new TriggerButton(joystick1, intakeNum, 0.3);
	outake = new TriggerButton(joystick1, outakeNum, 0.3);
	toteTurn = new JoystickButton(joystick2, toteTurnButtonNum);

	clawOveridePos->WhileHeld(new ClawOveride());
	clawOverideNeg->WhileHeld(new ClawOveride());

	clawOveridePos->WhenReleased(new StopClaw());
	clawOverideNeg->WhenReleased(new StopClaw());

	intake->WhenPressed(new ActuateIntake(true));
	outake->WhenPressed(new ActuateIntake(true));
	toteTurn->WhenPressed(new CodriverToteScoot());

	intake->WhileHeld(new RunIntake(-1.0));
	outake->WhileHeld(new RunIntake(1.0));

	intake->WhenReleased(new ActuateIntake(false));
	outake->WhenReleased(new ActuateIntake(false));

	intake->WhenReleased(new RunIntake(0.0));
	outake->WhenReleased(new RunIntake(0.0));

	feederHeight->WhenPressed(new GoToHeight(-55));

	desensitize = false;
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
	return Desensitize(0, 0.3, 2);
}

float OI::GetY() {
	return Desensitize(1, 0.3, 2);
}

float OI::GetR() {
	return Desensitize(4, 0.3, 2.5);
}

float OI::GetToteTurn() {
	return joystick2->GetRawAxis(toteTurnNum);
}

float OI::GetToteIntake() {
	return joystick2->GetRawAxis(toteIntakeNum);
}

float OI::GetClawOveride() {
	return joystick2->GetRawAxis(1);
}


float OI::Desensitize(int axisNumber, float threshold, float dsdivision) {
	float value = 0;
	if(fabs(joystick1->GetRawAxis(axisNumber)) > threshold) {
		if(joystick1->GetRawAxis(axisNumber) > 0) {
			value = (joystick1->GetRawAxis(axisNumber) - threshold) / (1 - threshold);
		} else {
			value = (joystick1->GetRawAxis(axisNumber) + threshold) / (1 - threshold);
		}
	}
	if(desensitize) {
		value = value / dsdivision;
		joystick1->SetRumble(joystick1->kLeftRumble, 0.5);
	} else {
		joystick1->SetRumble(joystick1->kLeftRumble, 0.0);
	}
	if(joystick1->GetRawButton(5)) {
		desensitize = !desensitize;
	}

	return value;
}

float OI::GetJoystick2POV() {
	return joystick2->GetPOV();
}
