// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static Encoder* drivetrainQuadratureEncoder1;
	static Encoder* drivetrainQuadratureEncoder2;
	static Encoder* drivetrainQuadratureEncoder3;
	static Encoder* drivetrainQuadratureEncoder4;
	static Gyro* drivetrainGyro1;
	static Encoder* clawHeightEncoder;
	static SpeedController* clawClawMotor;
	static DigitalInput* clawLevel0;
	static DigitalInput* clawLevel1;
	static DigitalInput* clawLevel2;
	static DigitalInput* clawLevel3;
	static DigitalInput* clawLevel4;
	static DigitalInput* clawLevel5;
	static DigitalInput* clawLevel6;
	static Encoder* clawPIDHeightEnccoder;
	static SpeedController* clawPIDClawMotor;
	static Relay* containerWinchContainerPull1;
	static Relay* containerWinchContainerPull2;
	static Relay* containerWinchContainerPull3;
	static DigitalInput* containerWinchContainerSensor1;
	static DigitalInput* containerWinchContainerSensor2;
	static DigitalInput* containerWinchContainerSenser3;
	static SpeedController* intakeSystemLeftIntake;
	static SpeedController* intakeSystemRightIntake;
	static DoubleSolenoid* intakeSystemLeftIntakeActuator;
	static DoubleSolenoid* intakeSystemRightIntakeActuator;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static CANTalon* drivetrainSpeedController2;
	static CANTalon* drivetrainSpeedController1;
	static CANTalon* drivetrainSpeedController3;
	static CANTalon* drivetrainSpeedController4;
	static RobotDrive* drivetrainRobotDrive;
	static CANTalon* clawPIDCANTalon;

	static void init();
};
#endif
