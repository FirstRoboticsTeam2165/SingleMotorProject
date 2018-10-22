
#pragma once

#include "ctre/Phoenix.h"
#include "WPILib.h"


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {

public:
// Declares smart pointers to form objects (instances) of libraries classes (see WIPLib, CTRLib,navXMXP C++ Lib)
// and provides access to class objects in Subsystems, e.g. robotDrive = RobotMap::diffDrive;
// (here motor1 provides private access to private version of singleMotor1) see Subsystem Motors.cpp


	static std::shared_ptr<WPI_TalonSRX> singleMotor1;

	static void init();

private:

	//	Mappings of IO channels relating the channel numbers to arguments in constructors
	//  of the motor controllers, actuators and sensors.

		static constexpr int MOTOR_1 = 1; //CAN ID for Talon motor1

};

