#ifndef ContainerGrabber_H
#define ContainerGrabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ContainerGrabber: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
//	DoubleSolenoid* solenoid;
	ContainerGrabber();
	void InitDefaultCommand();
	void SetSolenoid(bool actuate);
};

#endif
