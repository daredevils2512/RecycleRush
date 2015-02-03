/*
 * CodriverJoystickCustom.h
 *
 *  Created on: Jan 26, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_CODRIVERJOYSTICKCUSTOM_H_
#define SRC_CONTROLLER_CODRIVERJOYSTICKCUSTOM_H_

#include "CodriverBase.h"

class CodriverJoystickCustom: public CodriverBase {
	Joystick* stick2;
public:
	CodriverJoystickCustom(Joystick* joystick, Joystick* custom);

	virtual ~CodriverJoystickCustom();
};

#endif /* SRC_CONTROLLER_CODRIVERJOYSTICKCUSTOM_H_ */
