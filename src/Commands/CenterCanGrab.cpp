#include "CenterCanGrab.h"
#include "RunWinch.h"
#include "AutonDrive.h"
#include "AutonWait.h"
#include "AutonFastDrive.h"

CenterCanGrab::CenterCanGrab()
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
	AddParallel(new RunWinch(1, 1.0, 1.5));
	AddParallel(new RunWinch(2, 1.0, 1.5));
	AddSequential(new AutonWait(0.1));
	AddSequential(new AutonFastDrive(1.0, 1.0, 400));
	AddSequential(new AutonFastDrive(-1.0, -1.0, 400));
}
