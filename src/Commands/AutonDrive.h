#ifndef AutonDrive_H
#define AutonDrive_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Robot.h"

class AutonDrive: public CommandBase
{
private:
	float right;
	float left;
	float duration;

public:
	AutonDrive(float right, float left, int duration);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
