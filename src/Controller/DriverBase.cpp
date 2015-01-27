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
	return stick->GetRawAxis(drivingXAxis);
}

float DriverBase::GetDrivingY() {
	return stick->GetRawAxis(drivingYAxis);
}

float DriverBase::GetDrivingTwist() {
	return stick->GetRawAxis(drivingTwistAxis);
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

