#ifndef ReverseActuateIntake_H
#define ReverseActuateIntake_H

#include "../CommandBase.h"
#include "WPILib.h"

class ReverseActuateIntake: public CommandBase
{
public:
	bool value;
	ReverseActuateIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
