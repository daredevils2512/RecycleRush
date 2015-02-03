/*
 * CodriverController.h
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_CODRIVERBASE_H_
#define SRC_CONTROLLER_CODRIVERBASE_H_

#include "WPILib.h"
#include "TriggerButton.h"

class CodriverBase {
	Joystick* stick;

	JoystickButton* level1;
	JoystickButton* level2;
	JoystickButton* level3;
	JoystickButton* level4;
	JoystickButton* level5;
	JoystickButton* level6;
	JoystickButton* level7;
	JoystickButton* placeButton;
	JoystickButton* coopLevel;

	TriggerButton* clawOveridePos;
	TriggerButton* clawOverideNeg;

	int manualOverideAxis;
public:
	CodriverBase(
			Joystick* stick,
			int level1,
			int level2,
			int level3,
			int level4,
			int level5,
			int level6,
			int level7,
			int placeButton,
			int coopLevel,
			int manualOverideAxis);

	CodriverBase(
			Joystick* stick,
			JoystickButton* level1,
			JoystickButton* level2,
			JoystickButton* level3,
			JoystickButton* level4,
			JoystickButton* level5,
			JoystickButton* level6,
			JoystickButton* level7,
			JoystickButton* placeButton,
			JoystickButton* coopLevel,
			TriggerButton* clawOveridePos,
			TriggerButton* clawOverideNeg,
			int manualOverideAxis);

	virtual float GetManualOveride();

	JoystickButton* GetLevel1();
	JoystickButton* GetLevel2();
	JoystickButton* GetLevel3();
	JoystickButton* GetLevel4();
	JoystickButton* GetLevel5();
	JoystickButton* GetLevel6();
	JoystickButton* GetLevel7();
	JoystickButton* GetPlaceButton();
	JoystickButton* GetCoopLevel();
	TriggerButton* GetOverideButton1();
	TriggerButton* GetOverideButton2();

	virtual ~CodriverBase();

};

#endif /* SRC_CONTROLLER_CODRIVERBASE_H_ */
