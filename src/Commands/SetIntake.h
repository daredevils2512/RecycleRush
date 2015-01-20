#ifndef SetIntake_H
#define SetIntake_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Robot.h"

class SetIntake: public CommandBase
{
private:
	float left;
	float right;
public:
	SetIntake(float left, float right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
