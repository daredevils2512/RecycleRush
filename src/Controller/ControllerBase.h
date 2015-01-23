/*
 * Controller.h
 *
 *  Created on: Jan 19, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_
#include "WPILib.h"

class ControllerBase {
public:
	enum ControlType { XBOX, JOYSTICK, CUSTOM, NONE };

	ControllerBase(ControlType driver1Type, ControlType driver2Type, ControlType driver2Type2, Joystick* stick1, Joystick* stick2, Joystick* stick3);

	//Driver 1 Controls
	Joystick* driverStick;

	JoystickButton* driver1PlaceButton;

	int drivingXAxis;
	int drivingYAxis;
	int drivingTwistAxis;
	int intakeAxis;

	virtual float GetDrivingX() = 0;
	virtual float GetDrivingY() = 0;
	virtual float GetDrivingTwist() = 0;
	virtual float GetIntake() = 0;


	//Driver 2 Controls
	Joystick* driver2Stick1;
	Joystick* driver2Stick2;

	JoystickButton* level1;
	JoystickButton* level2;
	JoystickButton* level3;
	JoystickButton* level4;
	JoystickButton* level5;
	JoystickButton* level6;
	JoystickButton* level7;
	JoystickButton* driver2PlaceButton;
	JoystickButton* coopLevel;

	int manualOverideAxis;
	virtual float GetManualOveride() = 0;

	virtual JoystickButton* GetLevel1() = 0;
	virtual JoystickButton* GetLevel2() = 0;
	virtual JoystickButton* GetLevel3() = 0;
	virtual JoystickButton* GetLevel4() = 0;
	virtual JoystickButton* GetLevel5() = 0;
	virtual JoystickButton* GetLevel6() = 0;
	virtual JoystickButton* GetLevel7() = 0;
	virtual JoystickButton* GetDriver1PlaceButton() = 0;
	virtual JoystickButton* GetDriver2PlaceButton() = 0;
	virtual JoystickButton* GetCoopLevel() = 0;

};



#endif /* SRC_CONTROLLER_H_ */
