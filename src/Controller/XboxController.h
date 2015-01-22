/*
 * XboxController.h
 *
 *  Created on: Jan 19, 2015
 *      Author: Craig
 */

#ifndef SRC_XBOXCONTROLLER_H_
#define SRC_XBOXCONTROLLER_H_

#include "ControllerBase.h"

class XboxController: public ControllerBase {
public:
	XboxController(Joystick* stick1, Joystick* stick2, Joystick* stick3);
	virtual ~XboxController();
};

#endif /* SRC_XBOXCONTROLLER_H_ */
