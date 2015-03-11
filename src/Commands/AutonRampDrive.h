#ifndef AutonRampDrive_H
#define AutonRampDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonRampDrive: public CommandBase
{
	float left;
	float right;
	float distance;
	float startLeft;
	float startRight;
	float rampRate;
	bool rampDown;
	float lastTime;

public:
	AutonRampDrive(float right, float left, float distance, float startRight, float startLeft, bool rampDown, float rampRate);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
