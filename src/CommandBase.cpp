#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
Drivetrain* CommandBase::drivetrain = NULL;
ClawPID* CommandBase::clawpid = NULL;
OI* CommandBase::oi = NULL;
ContainerWinch* CommandBase::containerwinch = NULL;
IntakeSystem* CommandBase::intakesystem = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drivetrain = new Drivetrain();
	clawpid = new ClawPID();
	containerwinch = new ContainerWinch();
	intakesystem = new IntakeSystem();

	oi = new OI();
}
