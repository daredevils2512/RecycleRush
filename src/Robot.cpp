// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include "Commands/AutonomousMainCommand.h"
#include "Commands/AutonomousForward.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Drivetrain* Robot::drivetrain = 0;
ClawPID* Robot::clawPID = 0;
ContainerWinch* Robot::containerWinch = 0;
IntakeSystem* Robot::intakeSystem = 0;
OI* Robot::oi = 0;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	drivetrain = new Drivetrain();
	clawPID = new ClawPID();
	containerWinch = new ContainerWinch();
	intakeSystem = new IntakeSystem();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();

	// instantiate the command used for the autonomous period
	autonomousCommand = new AutonomousMainCommand(0);

	chooser = new SendableChooser();
//	chooser->AddDefault("Forward", new AutonomousForward());
	chooser->AddDefault("No Containers", new AutonomousMainCommand(0));
	chooser->AddObject("1 Containers", new AutonomousMainCommand(1));
	chooser->AddObject("2 Containers", new AutonomousMainCommand(2));
	chooser->AddObject("3 Containers", new AutonomousMainCommand(3));

	SmartDashboard::PutData("Autonomous Command", chooser);

  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	liftDown.WhenActive(new ResetLevelEncoder());

	autonomousCommand = (Command*) (chooser->GetSelected());

	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();

	if(Robot::clawPID->bottom->Get()) {
		Robot::clawPID->ResetHeightEncoder();
	}
	if(Robot::clawPID->heightEnccoder->GetRaw() > -122 && Robot::clawPID->heightEnccoder->GetRaw() != 0) {
		intakeSystem->ActuateIntake(false);
	}

	SmartDashboard::PutNumber("Front Right", Robot::drivetrain->frontRight->GetRaw());
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.

	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
	clawPID->Disable();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();


//	SmartDashboard::PutBoolean("Setting", Robot::intakeSystem->solenoid1->Get());
//	SmartDashboard::PutBoolean("Setting 2", Robot::intakeSystem->solenoid1->Get());
//	if(oi->getJoystick2()->GetRawButton(2)) {
//		intakeSystem->ActuateIntake(true);
//	} else {
//		intakeSystem->ActuateIntake(false);
//	}
//	if(oi->getJoystick3()->GetRawAxis(1) > 0.5 || oi->getJoystick3()->GetRawAxis(1) < -0.5) {
//		intakeSystem->SetIntakeMotors(oi->getJoystick3()->GetRawAxis(1), oi->getJoystick3()->GetRawAxis(1));
//	} else {
//		intakeSystem->SetIntakeMotors(0, 0);
//	}
	if(Robot::clawPID->bottom->Get()) {
		Robot::clawPID->ResetHeightEncoder();
	}
	if(Robot::clawPID->heightEnccoder->GetRaw() > -122 && Robot::clawPID->heightEnccoder->GetRaw() != 0) {
		intakeSystem->ActuateIntake(false);
	}

	SmartDashboard::PutBoolean("PID On Target", clawPID->OnTarget());
	SmartDashboard::PutNumber("PID Setpoint", clawPID->GetSetpoint());
	SmartDashboard::PutNumber("PID Position", clawPID->GetPosition());
	SmartDashboard::PutNumber("PID Output", clawPID->clawMotor->Get());
	SmartDashboard::PutBoolean("Setting", Robot::intakeSystem->doubleSolenoid1->Get());

	SmartDashboard::PutNumber("Gyro", Robot::drivetrain->GetGyro());

	SmartDashboard::PutNumber("DriverX", oi->GetX());
	SmartDashboard::PutNumber("DriverY", oi->GetY());
	SmartDashboard::PutNumber("DriverTwist", oi->GetR());

	SmartDashboard::PutNumber("Rear Right", Robot::drivetrain->rearRight->GetRaw());
	SmartDashboard::PutNumber("Rear Left", Robot::drivetrain->rearLeft->GetRaw());
	SmartDashboard::PutNumber("Front Right", Robot::drivetrain->frontRight->GetRaw());
	SmartDashboard::PutNumber("Front Left", Robot::drivetrain->frontLeft->GetRaw());

	SmartDashboard::PutNumber("Winch Encoder", Robot::clawPID->heightEnccoder->GetRaw());

	SmartDashboard::PutNumber("Bottom", Robot::clawPID->bottom->Get());

//	SmartDashboard::PutNumber("encoder1", Robot::drivetrain->quadratureEncoder1->Get());
//	SmartDashboard::PutNumber("encoder2", Robot::drivetrain->quadratureEncoder2->Get());
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

