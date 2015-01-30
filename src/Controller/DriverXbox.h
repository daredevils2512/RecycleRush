/*
 * DriverXbox.h
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_DRIVERXBOX_H_
#define SRC_CONTROLLER_DRIVERXBOX_H_

#include "DriverBase.h"
#include "TriggerButton.h"

class DriverXbox: public DriverBase {
private:
	TriggerButton* intakeButton;
	TriggerButton* outakeButton;

public:
	DriverXbox(Joystick* stick);
	virtual ~DriverXbox();

	TriggerButton* GetIntakeButton();
	TriggerButton* GetOutakeButton();
};

#endif /* SRC_CONTROLLER_DRIVERXBOX_H_ */
