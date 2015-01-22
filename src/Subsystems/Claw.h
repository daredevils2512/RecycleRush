// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef CLAW_H
#define CLAW_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Claw: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Encoder* heightEncoder;
	SpeedController* clawMotor;
	DigitalInput* level0;
	DigitalInput* level1;
	DigitalInput* level2;
	DigitalInput* level3;
	DigitalInput* level4;
	DigitalInput* level5;
	DigitalInput* level6;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	DigitalInput* level[7];

	Claw();
	void InitDefaultCommand();

	void SetMotor(float velocity);

	double GetHeight();

	bool GetLevel(int levelNumber);
};

#endif