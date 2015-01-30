#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/ClawPID.h"
#include "Subsystems/ContainerWinch.h"
#include "Subsystems/IntakeSystem.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static Drivetrain *drivetrain;
	static ClawPID *clawpid;
	static ContainerWinch *containerwinch;
	static IntakeSystem *intakesystem;
	static OI *oi;
};

#endif
