/*
 * DriverXbox.h
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_DRIVERXBOX_H_
#define SRC_CONTROLLER_DRIVERXBOX_H_

#include "DriverBase.h"

class DriverXbox: public DriverBase {
public:
	DriverXbox(Joystick* stick);
	virtual ~DriverXbox();
};

#endif /* SRC_CONTROLLER_DRIVERXBOX_H_ */
