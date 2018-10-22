/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RunMotorJoystick.h"


RunMotorJoystick::RunMotorJoystick() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::mtrCntrl.get());
}
// Called just before this Command runs the first time
void RunMotorJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RunMotorJoystick::Execute() {
	double m_joyY =  Robot::oi->getJoystick0()->GetY();  //  changed motor rotational direction in MotorCntrl.cpp
	Robot::mtrCntrl->SetRotationRate(m_joyY);
}

// Make this return true when this Command no longer needs to run execute()
bool RunMotorJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunMotorJoystick::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunMotorJoystick::Interrupted() {

}
