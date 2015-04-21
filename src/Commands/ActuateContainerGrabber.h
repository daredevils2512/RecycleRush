#ifndef ActuateContainerGrabber_H
#define ActuateContainerGrabber_H

#include "../CommandBase.h"
#include "WPILib.h"

class ActuateContainerGrabber: public CommandBase
{
	bool actuate;
public:
	ActuateContainerGrabber(bool actuate);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
