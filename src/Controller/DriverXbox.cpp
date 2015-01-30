/*
 * DriverXbox.cpp
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#include "DriverXbox.h"

DriverXbox::DriverXbox(Joystick* stick) :
	DriverBase(stick, 1, 1, 2, 4, 3),
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

