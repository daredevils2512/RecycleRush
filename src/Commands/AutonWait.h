#ifndef AutonWait_H
#define AutonWait_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonWait: public CommandBase
{
private:
	float waitTime;
public:
	AutonWait(float waitTime);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
