// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "HighGoalSpinWheels.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

HighGoalSpinWheels::HighGoalSpinWheels(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::highGoalSubsystem.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void HighGoalSpinWheels::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void HighGoalSpinWheels::Execute() {
	Robot::highGoalSubsystem->rightCanTalon->SetControlMode(Robot::highGoalSubsystem->rightCanTalon->kFollower);
	Robot::highGoalSubsystem->rightCanTalon->Set(5);  //set this to the canID of the left CanTalon

	if(Robot::oi->gethighGoalJoystick()->GetRawButton(1)) {
		Robot::highGoalSubsystem->leftCanTalon->Set(-.73);
	}

	if(Robot::oi->gethighGoalJoystick()->GetRawButton(3)) {
			Robot::highGoalSubsystem->leftCanTalon->Set(0);
	}

	if(Robot::oi->gethighGoalJoystick()->GetRawButton(4)){
		Robot::highGoalSubsystem->highGoalSolenoid->Set(true);
	}

	if(Robot::oi->gethighGoalJoystick()->GetRawButton(2)){
		Robot::highGoalSubsystem->highGoalSolenoid->Set(false);
	}
	//Make leftCanTalon go to full speed
	//printf("Setting Encoder Speed\n");
	//Robot::highGoalSubsystem->leftCanTalon->Set(-.85);
	//printf("DID SET Encoder Speed\n");

	//printf("---------%d---------\n", Robot::highGoalSubsystem->leftCanTalon->GetEncVel());
	// while(Robot::highGoalSubsystem->leftCanTalon->GetEncVel()<600) {
	//	End();
	// }
}

// Make this return true when this Command no longer needs to run execute()
bool HighGoalSpinWheels::IsFinished() {
	//printf("---------%d---------\n", Robot::highGoalSubsystem->leftCanTalon->GetEncVel());
	// printf("Checking encoder value in isFinished\n");
	// return Robot::highGoalSubsystem->leftCanTalon->GetEncVel()>=1000;
	return false;
}

// Called once after isFinished returns true
void HighGoalSpinWheels::End() {
	printf("I'm outta here");
	Robot::highGoalSubsystem->leftCanTalon->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HighGoalSpinWheels::Interrupted() {

}
