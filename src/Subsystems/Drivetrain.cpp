// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Drivetrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/DriveRobot.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	quadratureEncoder1 = RobotMap::drivetrainQuadratureEncoder1;
	quadratureEncoder2 = RobotMap::drivetrainQuadratureEncoder2;
	quadratureEncoder3 = RobotMap::drivetrainQuadratureEncoder3;
	quadratureEncoder4 = RobotMap::drivetrainQuadratureEncoder4;
	gyro1 = RobotMap::drivetrainGyro1;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	speedController2 = RobotMap::drivetrainSpeedController2;
	speedController1 = RobotMap::drivetrainSpeedController1;
	speedController3 = RobotMap::drivetrainSpeedController3;
	speedController4 = RobotMap::drivetrainSpeedController4;
	robotDrive = RobotMap::drivetrainRobotDrive;
	//Inversion settings for right side drive motors
	robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
	robotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, false);
	//Inversion settings for left side drive motors
	robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
	robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
}
    
void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new DriveRobot());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Drivetrain::Go(float magnitude, float angle) {
	robotDrive->Drive(magnitude, angle);
}

float Drivetrain::GetGyro() {
	return gyro1->GetAngle();
}
