/*
 * DriverController.h
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_DRIVERBASE_H_
#define SRC_CONTROLLER_DRIVERBASE_H_

#include "WPILib.h"

class DriverBase {
	Joystick* stick;

	JoystickButton* placeButton;

	int drivingXAxis;
	int drivingYAxis;
	int drivingTwistAxis;
	int intakeAxis;
public:
	DriverBase(Joystick* stick,
			int placeButton,
			int drivingXAxis,
			int drivingYAxis,
			int drivingTwistAxis,
			int intakeAxis);

	float GetDrivingX();
	float GetDrivingY();
	float GetDrivingTwist();
	float GetIntake();

	JoystickButton* GetPlaceButton();

	virtual ~DriverBase();
};

#endif /* SRC_CONTROLLER_DRIVERBASE_H_ */
