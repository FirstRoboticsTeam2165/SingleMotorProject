#pragma once

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*
 * RunMotorJoystick.h
 *
 *  Created on: Oct 7, 2018
 *      Author: Don Lauffer
 *****************************************************************************/
#include "Commands/Command.h"
#include "../OI.h"
//#include "Robot.h"
#include "../Robot.h"
#include "WPILib.h"
#include "../Subsystems/MotorCntrl.h"

class RunMotorJoystick : public Command {

private:



public:
	RunMotorJoystick();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};





