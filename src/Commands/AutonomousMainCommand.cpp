#include "AutonomousMainCommand.h"
#include "RunIntake.h"
#include "AutonDrive.h"
#include "RunWinch.h"
#include "GoToLevel.h"
#include "Place.h"
#include "ActuateIntake.h"
#include "AutonRunIntake.h"
#include "AutonWait.h"
#include "GoToHeight.h"

AutonomousMainCommand::AutonomousMainCommand(int containers, int totes)
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
	int autonLevel = 185;
	if(totes >= 1) {
		AddSequential(new GoToLevel(0));
		AddParallel(new GoToHeight(autonLevel));
	}
	if(totes >= 2) {
		AddSequential(new AutonDrive(0.30, 0.30, 900));
		AddSequential(new ActuateIntake(true));
		AddSequential(new AutonRunIntake(-1.0, 0.8));
		AddSequential(new ActuateIntake(false));
		AddSequential(new GoToLevel(0));
	}
	if(totes >= 3) {
		AddParallel(new GoToHeight(autonLevel));
		AddSequential(new AutonDrive(0.30, 0.30, 900));
		AddSequential(new ActuateIntake(true));
		AddSequential(new AutonRunIntake(-1.0, 0.6));
		AddParallel(new Place());
		AddSequential(new AutonRunIntake(-1.0, 0.5));
	}


	AddSequential(new AutonDrive(-0.40, 0.40, 580));

	if(totes >= 3) {
		AddSequential(new AutonDrive(-1.0, -1.0, 700));
		AddSequential(new AutonWait(0.85));
	} else {
		AddSequential(new AutonDrive(-1.0, -1.0, 700));
		AddSequential(new AutonWait(0.85));
	}

	AddSequential(new AutonDrive(0.40, -0.40, 580));

	AddSequential(new ActuateIntake(false));

	AddSequential(new AutonDrive(-1.0, -1.0, 200));
}
