#include "LiftDown.h"
#include "../Robot.h"

LiftDown::LiftDown()
{

}

bool LiftDown::Get()
{
//	return Robot::clawPID->GetBottom();
	return Robot::oi->getJoystick1()->GetRawButton(0);
}

