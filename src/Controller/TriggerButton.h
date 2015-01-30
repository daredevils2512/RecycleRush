/*
 * TriggerButton.h
 *
 *  Created on: Jan 30, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_TRIGGERBUTTON_H_
#define SRC_CONTROLLER_TRIGGERBUTTON_H_

#include <Buttons\Button.h>
#include <Joystick.h>

class TriggerButton: public Button {

private:
	Joystick *stick;
	int axis;
	float threshold;

public:
	TriggerButton(Joystick *joystick, int rawAxis, float pressThreshold) :
			stick(joystick), axis(rawAxis), threshold(pressThreshold) {
	}

	bool Get();
};

#endif /* SRC_CONTROLLER_TRIGGERBUTTON_H_ */
