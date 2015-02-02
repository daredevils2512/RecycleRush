/*
 * DriverXbox.cpp
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#include <cmath>
#include "DriverXbox.h"

DriverXbox::DriverXbox(Joystick* stick) :
	DriverBase(stick, 1, 0, 4, 1, 3),
	intakeButton(new TriggerButton(stick, 3, 0.3)),
	outakeButton(new TriggerButton(stick, 3, -0.3))
{

}

DriverXbox::~DriverXbox() {
	// TODO Auto-generated destructor stub
}

TriggerButton* DriverXbox::GetIntakeButton() {
	return intakeButton;
}

TriggerButton* DriverXbox::GetOutakeButton() {
	return outakeButton;
}

float DriverXbox::GetDrivingX() {
	float value = -stick->GetRawAxis(drivingXAxis);
	return Desensitize(value, 0.1);
}

float DriverXbox::GetDrivingY() {
	float value = -stick->GetRawAxis(drivingYAxis);
	return Desensitize(value, 0.1);
}

float DriverXbox::GetDrivingTwist() {
	float value = stick->GetRawAxis(drivingTwistAxis);
	return Desensitize(value, 0.1);
}



