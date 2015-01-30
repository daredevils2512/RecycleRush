/*
 * TriggerButton.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: Craig
 */

#include "TriggerButton.h"

bool TriggerButton::Get() {
	float axisValue = stick->GetRawAxis(axis);
	bool pressed = false;
	if (threshold > 0) {
		if (axisValue > threshold) {
			pressed = true;
		}
	} else {
		if (axisValue < threshold) {
			pressed = true;
		}
	}
	return pressed;
}
