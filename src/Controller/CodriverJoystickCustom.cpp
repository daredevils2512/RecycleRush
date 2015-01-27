/*
 * CodriverJoystickCustom.cpp
 *
 *  Created on: Jan 26, 2015
 *      Author: Craig
 */

#include "CodriverJoystickCustom.h"

CodriverJoystickCustom::CodriverJoystickCustom(Joystick* stick1, Joystick* stick2):
	CodriverBase(
			stick1,
			new JoystickButton(stick1, 1),
			new JoystickButton(stick1, 2),
			new JoystickButton(stick1, 3),
			new JoystickButton(stick2, 4),
			new JoystickButton(stick2, 5),
			new JoystickButton(stick2, 6),
			new JoystickButton(stick1, 7),
			new JoystickButton(stick2, 8),
			new JoystickButton(stick2, 9),
			1),
	stick2(stick2)
{

}

CodriverJoystickCustom::~CodriverJoystickCustom() {
}

