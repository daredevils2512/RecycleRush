/*
 * DriverJoystick.h
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_DRIVERJOYSTICK_H_
#define SRC_CONTROLLER_DRIVERJOYSTICK_H_

#include "DriverBase.h"

class DriverJoystick: public DriverBase {
public:
	DriverJoystick(Joystick* stick);
	virtual ~DriverJoystick();
};

#endif /* SRC_CONTROLLER_DRIVERJOYSTICK_H_ */
