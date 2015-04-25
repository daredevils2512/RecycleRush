#ifndef AutonStraif_H
#define AutonStraif_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonStraif: public CommandBase
{
	int duration;
public:
	AutonStraif(int duration);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
