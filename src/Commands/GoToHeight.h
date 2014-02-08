#ifndef GoToHeight_H
#define GoToHeight_H

#include "../CommandBase.h"
#include "WPILib.h"

class GoToHeight: public CommandBase
{
private:
	float targetHeight;
	bool goingDown;
public:
	GoToHeight(float targetHeight);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
