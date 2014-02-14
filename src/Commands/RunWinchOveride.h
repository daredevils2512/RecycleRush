#ifndef RunWinchOveride_H
#define RunWinchOveride_H

#include "../CommandBase.h"
#include "WPILib.h"

class RunWinchOveride: public CommandBase
{
	int winchNumber;
	float speed;
public:
	RunWinchOveride(int winchNumber, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
