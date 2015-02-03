/*
 * CodriverJoystickCustom.cpp
 *
 *  Created on: Jan 26, 2015
 *      Author: Craig
 */

#include "CodriverJoystickCustom.h"

CodriverJoystickCustom::CodriverJoystickCustom(Joystick* joystick, Joystick* custom):
	CodriverBase(
			joystick,
			new JoystickButton(custom, 16),
			new JoystickButton(custom, 5),
			new JoystickButton(custom, 4),
			new JoystickButton(custom, 8),
			new JoystickButton(custom, 6),
			new JoystickButton(custom, 2),
			new JoystickButton(custom, 7), //Recycling
			new JoystickButton(custom, 14),
			new JoystickButton(custom, 15),
			new TriggerButton(joystick, 1, 0.2),
			new TriggerButton(joystick, 1, -0.2),
			//TODO: need Reset for 3
			1),
	stick2(custom)
{

}

CodriverJoystickCustom::~CodriverJoystickCustom() {
}

