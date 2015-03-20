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
#include "Commands/AutonomousCommand.h"
#include "Commands/AutonomousMainCommand.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Drivetrain* Robot::drivetrain = 0;
ClawPID* Robot::clawPID = 0;
ContainerWinch* Robot::containerWinch = 0;
IntakeSystem* Robot::intakeSystem = 0;
LEDindicator* Robot::lEDindicator = 0;
OI* Robot::oi = 0;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

bool Robot::centered = false;

void Robot::RobotInit() {
	RobotMap::init();

	prevCenter = false;
	intaking = false;
	prevprevCentered = false;
//	centered = false;

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	drivetrain = new Drivetrain();
	clawPID = new ClawPID();
	containerWinch = new ContainerWinch();
	intakeSystem = new IntakeSystem();
	lEDindicator = new LEDindicator();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();

	// instantiate the command used for the autonomous period
	autonomousCommand = new AutonomousMainCommand(1, 1, false);

	chooser = new SendableChooser();
	chooser->AddDefault("Do Nothing", new AutonomousMainCommand(0, 0, true));
	chooser->AddObject("Just Drive", new AutonomousMainCommand(0, 0, false));
	chooser->AddObject("No Containers, All Totes", new AutonomousMainCommand(0, 3, false));
	chooser->AddObject("1 Containers, All Totes", new AutonomousMainCommand(1, 3, false));
	chooser->AddObject("2 Containers, All Totes", new AutonomousMainCommand(2, 3, false));
	chooser->AddObject("3 Containers, All Totes", new AutonomousMainCommand(3, 3, false));
	chooser->AddObject("No Containers, 1 Tote", new AutonomousMainCommand(0, 1, false));
	chooser->AddObject("No Containers, 2 Totes", new AutonomousMainCommand(0, 2, false));
	chooser->AddObject("1 Container", new AutonomousMainCommand(1, 0, false));
	chooser->AddObject("2 Containers", new AutonomousMainCommand(2, 0, false));

	SmartDashboard::PutData("Autonomous Command", chooser);

//	CameraServer::GetInstance()->SetQuality(10);
//	CameraServer::GetInstance()->StartAutomaticCapture("cam0");

//	CameraServer::GetInstance()->StartAutomaticCapture("cam0");
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
//	liftDown.WhenActive(new ResetLevelEncoder());
	drivetrain->gyro1->Reset();

	intakeSystem->ActuateIntake(false);

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

	if(drivetrain->gyro1->GetAngle() >= 20 || drivetrain->gyro1->GetAngle() <= -20) {
		autonomousCommand->Cancel();
		clawPID->SetSetpoint(clawPID->heightEnccoder->GetRaw() - 100);
	}

}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.

	drivetrain->gyro1->Reset();
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
	clawPID->Disable();
	intakeSystem->ActuateIntake(false);
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

//	SmartDashboard::PutData("Camera", CameraServer::GetInstance());

//	Robot::containerWinch->containerPull1->Set(0.5);
//	Robot::containerWinch->containerPull2->Set(0.5);

//	SmartDashboard::PutBoolean("Setting", Robot::intakeSystem->solenoid1->Get());
//	SmartDashboard::PutBoolean("Setting 2", Robot::intakeSystem->solenoid1->Get());

	if(Robot::clawPID->bottom->Get()) {
		Robot::clawPID->ResetHeightEncoder();
	}

//	if((prevCenter == false && oi->getJoystick1()->GetRawButton(6) == true) && centered == false) {
//		centered = true;
//	} else if ((prevCenter == false && oi->getJoystick1()->GetRawButton(6) == true) && centered == true) {
//		centered = false;
//	}
//	prevCenter = oi->getJoystick1()->GetRawButton(6);
//
//	if((oi->getJoystick1()->GetRawAxis(2) < 0.3 && oi->getJoystick1()->GetRawAxis(2) > -0.3) && (oi->getJoystick1()->GetRawAxis(3) < 0.3 && oi->getJoystick1()->GetRawAxis(3) > -0.3)) {
//		if(centered) {
//			intakeSystem->ActuateIntake(true);
//		} else {
//			intakeSystem->ActuateIntake(false);
//		}
//	}

//	Actuates the intake arms when the lift comes down
	if(oi->getJoystick1()->GetRawButton(10) == false) {
		 SafetyCheck(-150);
	}


	if((Robot::oi->getJoystick2()->GetRawButton(3) || Robot::oi->getJoystick2()->GetRawButton(4)) || (Robot::oi->getJoystick2()->GetRawButton(5) || Robot::oi->getJoystick2()->GetRawButton(6))) {

	} else {
		if(Robot::oi->GetJoystick2POV() == 0) {
			Robot::containerWinch->SetWinch(1, -1.0);
			Robot::containerWinch->SetWinch(2, -1.0);
		} else if(Robot::oi->GetJoystick2POV() == 180) {
			Robot::containerWinch->SetWinch(1, 1.0);
			Robot::containerWinch->SetWinch(2, 1.0);
		} else {
			Robot::containerWinch->SetWinch(1, 0.0);
			Robot::containerWinch->SetWinch(2, 0.0);
		}
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
	SmartDashboard::PutNumber("Top", Robot::clawPID->top->Get());

	SmartDashboard::PutBoolean("Desensitized", Robot::oi->desensitize);

	SmartDashboard::PutNumber("PDP Port 2 Amp Draw", pdp.GetCurrent(2));
	SmartDashboard::PutNumber("PDP Port 3 Amp Draw", pdp.GetCurrent(3));
}

void Robot::TestPeriodic() {
	lw->Run();
}
void Robot::SafetyCheck( int threshold){
	if((Robot::clawPID->heightEnccoder->GetRaw() > threshold && Robot::clawPID->bottom->Get() == false) && intakeSystem->GetCooperatition() == false) {
		intakeSystem->ActuateIntake(false);
		centered = false;

	}
	if (Robot::clawPID->heightEnccoder->GetRaw() <= threshold) {
		intakeSystem->SetCooperatition(false);
	}
}

START_ROBOT_CLASS(Robot);

