#ifndef GOTOLEVEL_H
#define GOTOLEVEL_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class GoToLevel: public Command {
private:
	int level;
public:
	GoToLevel(int level);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
