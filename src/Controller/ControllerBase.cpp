/*
 * ControllerBase.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: Craig
 */
#include "ControllerBase.h"
/*driver1Type - enum for controller that the primary driver is using
 *
 */
ControllerBase::ControllerBase(ControlType driver1Type, ControlType driver2Type, ControlType driver2Type2, Joystick* stick1, Joystick* stick2, Joystick* stick3) {
	driverStick = stick1;
	driver2Stick1 = stick2;
	driver2Stick2 = stick3;

	switch (driver2Type2) {
	case ControlType::JOYSTICK:
		manualOverideAxis = 1;
		break;
	}
}

float GetDrivingX() {
	return driverStick.GetRawAxis(driverXAxis);
}

float GetDrivingY() {

}

float GetDrivingTwist() {

}

float GetIntake() {

}

float GetManualOveride() {

}

JoystickButton* ControllerBase::GetLevel1() {
	return level1;
}

JoystickButton* ControllerBase::GetLevel2() {
	return level2;
}

JoystickButton* ControllerBase::GetLevel3() {
	return level3;
}

JoystickButton* ControllerBase::GetLevel4() {
	return level4;
}

JoystickButton* ControllerBase::GetLevel5() {
	return level5;
}

JoystickButton* ControllerBase::GetLevel6() {
	return level6;
}

JoystickButton* ControllerBase::GetLevel7() {
	return level7;
}

JoystickButton* ControllerBase::GetDriver1PlaceButton() {
	return driver1PlaceButton;
}

JoystickButton* ControllerBase::GetDriver2PlaceButton() {
	return driver2PlaceButton;
}

JoystickButton* ControllerBase::GetCoopLevel() {
	return coopLevel;
}
