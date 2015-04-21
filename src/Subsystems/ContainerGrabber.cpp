#include "ContainerGrabber.h"
#include "../RobotMap.h"

ContainerGrabber::ContainerGrabber() :
		Subsystem("ExampleSubsystem")
{
	solenoid = RobotMap::canGrabberSolenoid;
}

void ContainerGrabber::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ContainerGrabber::SetSolenoid(bool actuate)
{
	if (actuate == true) {
		solenoid->Set(DoubleSolenoid::kForward);
	}else {
		solenoid->Set(DoubleSolenoid::kReverse);
	}
}

