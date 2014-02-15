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
#include "WinchDriveToContainer.h"
#include "AutonPickUp.h"

AutonomousMainCommand::AutonomousMainCommand(int containers, int totes, bool doNothing)
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

	if(doNothing == false) {
		if(totes >= 1) {
			// Pick up tote 1 & container 1
			AddSequential(new GoToLevel(0));
			if(containers >= 1) AddParallel(new RunWinch(1, 1, 2.7));
			AddParallel(new GoToHeight(autonLevel));
			if(containers >= 1) AddSequential(new AutonWait(0.25));
		}
		if(totes >= 2) {
			// Pick up tote 2 & container 2
			if(containers >= 2) AddParallel(new WinchDriveToContainer());
			AddSequential(new AutonDrive(0.30, 0.30, 900));
			AddSequential(new ActuateIntake(true));
			AddSequential(new AutonRunIntake(-1.0, 0.8));
			if(totes != 2) {
				AddSequential(new ActuateIntake(false));
				AddSequential(new Place());
			}
			if(totes == 2) {
				AddParallel(new Place());
			}

		}
		if(totes >= 3) {
			// Pick up tote 3 & container 3
			if(containers >= 2) {
				AddParallel(new AutonPickUp());
			} else {
				AddParallel(new GoToHeight(autonLevel));
			}
			AddSequential(new AutonDrive(0.30, 0.30, 900));

			AddSequential(new ActuateIntake(true));
			AddSequential(new AutonRunIntake(-1.0, 0.6));
			AddParallel(new Place());
			AddSequential(new AutonRunIntake(-1.0, 0.2));
		}

		// 1st turn (at third tote) depending on the amount of weight that will be on the robot
		if(totes >= 3) {
			if(containers > 0) {
				AddSequential(new AutonDrive(-0.75, 0.75, 950));
				AddParallel(new AutonRunIntake(-1.0, 0.5));
			} else {
				AddSequential(new AutonDrive(-0.80, 0.80, 500));
			}
		} else if (totes > 0) {
			AddSequential(new AutonDrive(-0.60, 0.60, 600));
		}

		// Drive to scoring zone
		if(totes >= 3) {
			if(containers > 0) {
				AddSequential(new AutonDrive(-1.0, -1.0, 550));
			} else {
				AddSequential(new AutonDrive(-1.0, -1.0, 800));
				AddSequential(new AutonWait(0.85));
			}
		} else {
			AddSequential(new AutonDrive(-0.5, -0.5, 650));
			//825
			AddSequential(new AutonWait(0.85));
		}

		// Turn in scoring zone before releasing totes
		if(totes >= 3) {
			if(containers > 0) {
				//J turn for 3 tote 2 container
				AddSequential(new AutonDrive(-0.15, -1.0, 1600));
			} else {
				AddSequential(new AutonDrive(0.60, -0.60, 580));
			}
		}
		//580

		// Release totes
		if(totes > 0) {
			AddSequential(new ActuateIntake(false));
			if(totes <= 2) {
				AddSequential(new GoToLevel(0));
			}
		}

		// Drive away from totes
		if(totes >= 3) {
			if(containers > 0) {
				AddSequential(new AutonDrive(-1.0, -1.0, 300));
				AddSequential(new AutonDrive(-1.0, -0.10, 200));
				AddSequential(new AutonDrive(-0.75, 0.75, 200));
				AddSequential(new AutonDrive(-0.5, -0.5, 100));
			} else {
				AddSequential(new AutonDrive(-1.0, -1.0, 400));
			}
		} else if (totes > 0) {
			AddSequential(new AutonDrive(-1.0, -1.0, 250));
		}

		// Turn so containers fit in the scoring zone
		if(containers > 0) {
	//		AddSequential(new AutonDrive(-1.0, 1.0, 300));
		}
	}
}
