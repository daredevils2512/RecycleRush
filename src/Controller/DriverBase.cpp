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
	if(abs(stick->GetRawAxis(drivingXAxis) > 0.1)) {
		return stick->GetRawAxis(drivingXAxis);
	} else {
		return 0.0;
	}
}

float DriverBase::GetDrivingY() {
	if(abs(stick->GetRawAxis(drivingYAxis) > 0.1)) {
		return stick->GetRawAxis(drivingYAxis);
	} else {
		return 0.0;
	}
}

float DriverBase::GetDrivingTwist() {
	if(abs(stick->GetRawAxis(drivingTwistAxis) > 0.1)) {
		return stick->GetRawAxis(drivingTwistAxis);
	} else {
		return 0.0;
	}
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

