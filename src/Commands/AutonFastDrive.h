#ifndef AutonFastDrive_H
#define AutonFastDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonFastDrive: public CommandBase
{
	float right;
	float left;
	float duration;
public:
	AutonFastDrive(float right, float left, int duration);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
