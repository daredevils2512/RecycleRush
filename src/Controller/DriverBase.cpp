/*
 * DriverController.cpp
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#include "DriverBase.h"

DriverBase::DriverBase(
		Joystick* stick,
		int placeButton,
		int drivingXAxis,
		int drivingYAxis,
		int drivingTwistAxis,
		int intakeAxis) :
	stick(stick),
	placeButton(new JoystickButton(stick, placeButton)),
	drivingXAxis(drivingXAxis),
	drivingYAxis(drivingYAxis),
	drivingTwistAxis(drivingTwistAxis),
	intakeAxis(intakeAxis)
	 {
}

float DriverBase::GetDrivingX() {
	float value = 0;
	if(stick->GetRawAxis(drivingXAxis) > 0.1 || stick->GetRawAxis(drivingXAxis) < -0.1) {
		value = -stick->GetRawAxis(drivingXAxis);
	}
	return value;
}

float DriverBase::GetDrivingY() {
	float value = 0;
	if(stick->GetRawAxis(drivingYAxis) > 0.1 || stick->GetRawAxis(drivingYAxis) < -0.1) {
		value = -stick->GetRawAxis(drivingYAxis);
	}
	return value;
}

float DriverBase::GetDrivingTwist() {
	float value = 0;
	if(stick->GetRawAxis(drivingTwistAxis) > 0.1 || stick->GetRawAxis(drivingTwistAxis) < -0.1) {
		value = -stick->GetRawAxis(drivingTwistAxis);
	}
	return value;
}


float DriverBase::GetIntake() {
	return stick->GetRawAxis(intakeAxis);
}

JoystickButton* DriverBase::GetPlaceButton() {
	return placeButton;
}

DriverBase::~DriverBase() {
	// TODO Auto-generated destructor stub
}

