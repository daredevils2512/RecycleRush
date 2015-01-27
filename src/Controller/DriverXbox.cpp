/*
 * DriverXbox.cpp
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#include "DriverXbox.h"

DriverXbox::DriverXbox(Joystick* stick) :
	DriverBase(stick, 1, 2, 3, 4, 5)
{

}

DriverXbox::~DriverXbox() {
	// TODO Auto-generated destructor stub
}

