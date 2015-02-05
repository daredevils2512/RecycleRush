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
			new JoystickButton(stick1, 7),
			new JoystickButton(stick1, 8),
			new JoystickButton(stick1, 9),
			new JoystickButton(stick1, 10),
			new JoystickButton(stick1, 11),
			new JoystickButton(stick1, 12),
			new JoystickButton(stick1, 4),
			new JoystickButton(stick1, 5),
			new JoystickButton(stick1, 6),
			1),
	stick2(stick2)
{

}

CodriverJoystickCustom::~CodriverJoystickCustom() {
}

