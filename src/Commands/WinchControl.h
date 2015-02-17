#ifndef WinchControl_H
#define WinchControl_H

#include "../CommandBase.h"
#include "WPILib.h"

class WinchControl: public CommandBase
{
public:
	WinchControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
