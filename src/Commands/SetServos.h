#ifndef SetServos_H
#define SetServos_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetServos: public CommandBase
{
	bool out;
public:
	SetServos(bool out);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
