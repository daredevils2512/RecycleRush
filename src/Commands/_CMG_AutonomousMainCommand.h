#ifndef _CMG_AutonomousMainCommand_H
#define _CMG_AutonomousMainCommand_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "../Robot.h"

class _CMG_AutonomousMainCommand: public CommandGroup
{
public:
	_CMG_AutonomousMainCommand(int containers, int totes, bool doNothing);
};

#endif
