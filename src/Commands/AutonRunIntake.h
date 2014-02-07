#ifndef AutonRunIntake_H
#define AutonRunIntake_H

#include "../CommandBase.h"
#include "../Robot.h"
#include "WPILib.h"

class AutonRunIntake: public CommandBase
{
private:
	float velocity;
	float duration;

public:


	AutonRunIntake(float velocity, float duration);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
