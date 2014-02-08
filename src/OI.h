// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Controller/DriverBase.h"
#include "Controller/CodriverBase.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Joystick* joystick3;
	Joystick* joystick2;
	Joystick* joystick1;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	 DriverBase* driverController;
	 CodriverBase* codriverController;

	 JoystickButton* tempLevel1;
	 JoystickButton* resetButton;
	 JoystickButton* pickUp;

	 TriggerButton* clawOveridePos;
	 TriggerButton* clawOverideNeg;

	 TriggerButton* intake;
	 TriggerButton* outake;
public:
	OI();
 
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	Joystick* getJoystick1();
	Joystick* getJoystick2();
	Joystick* getJoystick3();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	float GetX();
	float GetY();
	float GetR();
	float GetClawOveride();
	float Desensitize(int axisNumber, float threshold);
};

#endif
