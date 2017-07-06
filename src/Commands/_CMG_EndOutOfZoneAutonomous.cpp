#include "_CMG_AutonPickUp.h"
#include "_CMG_EndOutOfZoneAutonomous.h"
#include "_CMG_WinchDriveToContainer.h"
#include "RunIntake.h"
#include "AutonDrive.h"
#include "RunWinch.h"
#include "GoToLevel.h"
#include "Place.h"
#include "ActuateIntake.h"
#include "AutonRunIntake.h"
#include "AutonWait.h"
#include "GoToHeight.h"
#include "AutonRampDrive.h"

_CMG_EndOutOfZoneAutonomous::_CMG_EndOutOfZoneAutonomous()
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

	int autonLevel = -185;

	// Pick up tote 1 & container 1
	AddSequential(new GoToLevel(0));
	AddParallel(new RunWinch(1, 1, 2.7));
	AddParallel(new GoToHeight(autonLevel));
	AddSequential(new AutonWait(0.25));

	// Pick up tote 2 & container 2
	AddParallel(new _CMG_WinchDriveToContainer());
	AddSequential(new AutonDrive(0.30, 0.30, 900));
	AddSequential(new ActuateIntake(true));
	AddSequential(new AutonRunIntake(-1.0, 0.8));
	AddSequential(new ActuateIntake(false));
	AddSequential(new Place());

	// Pick up tote 3 & container 3
	AddParallel(new _CMG_AutonPickUp());
	AddSequential(new AutonDrive(0.30, 0.30, 900));

	AddSequential(new ActuateIntake(true));
	AddSequential(new AutonRunIntake(-1.0, 0.6));
	AddSequential(new ActuateIntake(false));
	AddSequential(new Place());
	AddSequential(new ActuateIntake(true));

	// 1st turn (at third tote) depending on the amount of weight that will be on the robot
	AddSequential(new AutonDrive(0.65, -0.65, 660));
	AddParallel(new AutonRunIntake(-1.0, 0.5));

	// Drive to scoring zone
	AddSequential(new AutonRampDrive(-1.0, -1.0, 950, -0.5, -0.5, false, 0.1));
	AddSequential(new AutonWait(1.5));

	//Release totes
	AddSequential(new ActuateIntake(false));
	AddSequential(new AutonDrive(-0.8, -0.8, 300));
}
