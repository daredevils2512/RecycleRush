/*
 * CodriverJoystick.h
 *
 *  Created on: Jan 26, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_CODRIVERJOYSTICK_H_
#define SRC_CONTROLLER_CODRIVERJOYSTICK_H_

#include "CodriverBase.h"

class CodriverJoystick: public CodriverBase {
public:
	CodriverJoystick(Joystick* stick);
	virtual ~CodriverJoystick();
};

#endif /* SRC_CONTROLLER_CODRIVERJOYSTICK_H_ */
