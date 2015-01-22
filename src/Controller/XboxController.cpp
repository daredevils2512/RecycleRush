/*
 * XboxController.cpp
 *
 *  Created on: Jan 19, 2015
 *      Author: Craig
 */

#include "XboxController.h"

XboxController::XboxController(Joystick* stick1, Joystick* stick2, Joystick* stick3) {
	level1 = new JoystickButton(stick1, 1);
	level2 = new JoystickButton(stick1, 1);
	level3 = new JoystickButton(stick1, 1);
	level4 = new JoystickButton(stick1, 1);
	level5 = new JoystickButton(stick1, 1);
	level6 = new JoystickButton(stick1, 1);
	level7 = new JoystickButton(stick1, 1);
	driver1PlaceButton = new JoystickButton(stick1, 1);
	driver2PlaceButton = new JoystickButton(stick1, 1);
	coopLevel = new JoystickButton(stick1, 1);
}

XboxController::~XboxController() {
	// TODO Auto-generated destructor stub
}
