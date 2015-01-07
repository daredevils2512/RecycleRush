#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
Drivetrain* CommandBase::drivetrain = NULL;
Claw* CommandBase::claw = NULL;
ClawPID* CommandBase::clawpid = NULL;
OI* CommandBase::oi = NULL;

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
	claw = new Claw();
	clawpid = new ClawPID();

	oi = new OI();
}
