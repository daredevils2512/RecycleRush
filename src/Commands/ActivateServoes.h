#ifndef ActivateServoes_H
#define ActivateServoes_H

#include "../CommandBase.h"
#include "WPILib.h"

class ActivateServoes: public CommandBase
{
bool out;
public:
	ActivateServoes();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
