/*
 * DriverController.h
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_DRIVERBASE_H_
#define SRC_CONTROLLER_DRIVERBASE_H_

#include "WPILib.h"
#include "TriggerButton.h"

class DriverBase {

protected:
	Joystick* stick;
private:
	JoystickButton* placeButton;
protected:
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

	virtual float GetDrivingX();
	virtual float GetDrivingY();
	virtual float GetDrivingTwist();
	float GetIntake();

	JoystickButton* GetPlaceButton();

	virtual TriggerButton* GetIntakeButton() = 0;

	virtual TriggerButton* GetOutakeButton() = 0;

	float Desensitize(float value, float sensitivity);

	virtual ~DriverBase();
};

#endif /* SRC_CONTROLLER_DRIVERBASE_H_ */
