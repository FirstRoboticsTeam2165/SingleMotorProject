/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MotorCntrl.h"

#include "../RobotMap.h"
#include "../Commands/RunMotorJoystick.h"


MotorCntrl::MotorCntrl() : Subsystem("MotorCntrl") {

	cntrl_1 = RobotMap::singleMotor1;
	rot_rate = 0.0;

	cntrl_1->SetSafetyEnabled(false);
	cntrl_1->Set(ControlMode::PercentOutput,0.0);  // set motor speed to 0.0
	cntrl_1->SetNeutralMode(NeutralMode::Brake);
	cntrl_1->SetInverted(false);  // changes motor rotational direction

}

void MotorCntrl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new RunMotorJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

	void MotorCntrl::SetRotationRate(double rot_rate){
		cntrl_1->Set(rot_rate); // rotational speed of motor determined by position of joystick
	}
