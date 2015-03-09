#ifndef CodriverToteScoot_H
#define CodriverToteScoot_H

#include "../CommandBase.h"
#include "WPILib.h"

class CodriverToteScoot: public CommandBase
{
public:
	CodriverToteScoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
