#ifndef AutonDrive_H
#define AutonDrive_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Robot.h"

class AutonDrive: public CommandBase
{
private:
	float magnitude;
	float angle;
	float duration;

public:
	AutonDrive(float magnitude, float angle, float duration);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
