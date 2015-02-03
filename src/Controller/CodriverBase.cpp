/*
 * CodriverController.cpp
 *
 *  Created on: Jan 23, 2015
 *      Author: Craig
 */

#include "CodriverBase.h"
#include "TriggerButton.h"

CodriverBase::CodriverBase(
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
		int manualOverideAxis):
		stick(stick),
		level1(new JoystickButton(stick, level1)),
		level2(new JoystickButton(stick, level2)),
		level3(new JoystickButton(stick, level3)),
		level4(new JoystickButton(stick, level4)),
		level5(new JoystickButton(stick, level5)),
		level6(new JoystickButton(stick, level6)),
		level7(new JoystickButton(stick, level7)),
		placeButton(new JoystickButton(stick, placeButton)),
		coopLevel(new JoystickButton(stick, coopLevel)),
		clawOveridePos(new TriggerButton(stick, 4, 0.2)),
		clawOverideNeg(new TriggerButton(stick, 4, 0.2)),
		manualOverideAxis(manualOverideAxis)
{

}

CodriverBase::CodriverBase(
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
		int manualOverideAxis):
		stick(stick),
		level1(level1),
		level2(level2),
		level3(level3),
		level4(level4),
		level5(level5),
		level6(level6),
		level7(level7),
		placeButton(placeButton),
		coopLevel(coopLevel),
		clawOveridePos(clawOveridePos),
		clawOverideNeg(clawOverideNeg),
		manualOverideAxis(manualOverideAxis)
{

}

float CodriverBase::GetManualOveride() {
	return stick->GetRawAxis(manualOverideAxis);
}

JoystickButton* CodriverBase::GetLevel1() {
	return level1;
}

JoystickButton* CodriverBase::GetLevel2() {
	return level2;
}

JoystickButton* CodriverBase::GetLevel3() {
	return level3;
}

JoystickButton* CodriverBase::GetLevel4() {
	return level4;
}

JoystickButton* CodriverBase::GetLevel5() {
	return level5;
}

JoystickButton* CodriverBase::GetLevel6() {
	return level6;
}

JoystickButton* CodriverBase::GetLevel7() {
	return level7;
}

JoystickButton* CodriverBase::GetPlaceButton() {
	return placeButton;
}

JoystickButton* CodriverBase::GetCoopLevel() {
	return coopLevel;
}

TriggerButton* CodriverBase::GetOverideButton1() {
	return clawOveridePos;
}

TriggerButton* CodriverBase::GetOverideButton2() {
	return clawOverideNeg;
}


CodriverBase::~CodriverBase() {
	delete level1;
	delete level2;
	delete level3;
	delete level4;
	delete level5;
	delete level6;
	delete level7;
	delete placeButton;
	delete coopLevel;
}

