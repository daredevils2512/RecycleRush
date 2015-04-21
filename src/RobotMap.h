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
	static Encoder* drivetrainrearRight;
	static Encoder* drivetrainrearLeft;
	static Encoder* drivetrainfrontLeft;
	static Encoder* drivetrainfrontRight;
	static Gyro* drivetrainGyro1;
	static DigitalInput* clawPIDBottom;
	static DigitalInput* clawPIDTop;
	static Encoder* clawPIDHeightEnccoder;
	static Victor* containerWinchContainerPull1;
	static Victor* containerWinchContainerPull2;
	static SpeedController* intakeSystemLeftIntake;
	static SpeedController* intakeSystemRightIntake;
	static DoubleSolenoid* intakeSystemDoubleSolenoid1;
	static DoubleSolenoid* canGrabberSolenoid;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static CANTalon* drivetrainSpeedController2;
	static CANTalon* drivetrainSpeedController1;
	static CANTalon* drivetrainSpeedController3;
	static CANTalon* drivetrainSpeedController4;
	static RobotDrive* drivetrainRobotDrive;
	static CANTalon* clawPIDCANTalon;
	static CANTalon* clawMotor2;

	static Servo* testServo;
	static Servo* testServo2;

	static void init();
};
#endif
