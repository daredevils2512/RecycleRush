/*
 * CodriverJoystick.cpp
 *
 *  Created on: Jan 26, 2015
 *      Author: Craig
 */

#include "CodriverJoystick.h"

CodriverJoystick::CodriverJoystick(Joystick* stick):
	CodriverBase(stick, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1)
{
}

CodriverJoystick::~CodriverJoystick() {
}
