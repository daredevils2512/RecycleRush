#include "AutonomousMainCommand.h"
#include "RunIntake.h"
#include "AutonDrive.h"
#include "RunWinch.h"
#include "GoToLevel.h"
#include "Place.h"

AutonomousMainCommand::AutonomousMainCommand(int containers)
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	AddSequential(new RunIntake(1.0));


	if (containers > 0) AddParallel(new RunWinch(1, 1.0));
	if (containers > 1) AddParallel(new RunWinch(2, 1.0));
	AddSequential(new AutonDrive(0.25, 0, 1));
	AddSequential(new GoToLevel(0));

	if (containers > 1) AddParallel(new RunWinch(2, 1.0));
	if (containers > 2) AddParallel(new RunWinch(3, 1.0));
	AddSequential(new AutonDrive(0.25, 0, 1));
	// ratchet
	AddSequential(new GoToLevel(0));

	if (containers > 2) AddParallel(new RunWinch(3, 1.0));
	AddSequential(new AutonDrive(0.25, 0, 1));
	// ratchet

	AddSequential(new AutonDrive(0.25, 90, 1));
	AddSequential(new AutonDrive(0.25, 0, 1));

	AddSequential(new GoToLevel(0));
	AddSequential(new Place());
}
