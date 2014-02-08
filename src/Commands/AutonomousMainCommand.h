#ifndef AutonomousMainCommand_H
#define AutonomousMainCommand_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "../Robot.h"

class AutonomousMainCommand: public CommandGroup
{
public:
	AutonomousMainCommand(int containers, int totes);
};

#endif
