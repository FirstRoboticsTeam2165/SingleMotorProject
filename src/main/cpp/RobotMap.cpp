

#include "RobotMap.h"
#include "WPILib.h"

	std::shared_ptr<WPI_TalonSRX> RobotMap::singleMotor1; // address of TalonSRX for motor 1 instance is set to motor_1 in Motors.cpp

	void RobotMap::init() {

// Assign a shared_ptr to an object formed from software libraries, e.g., makes pneumaticShift point to new DoubleSolenoid()
// constexpr int in Talon() arguments refer to CAN IDs for motor controller

	singleMotor1.reset(new WPI_TalonSRX(MOTOR_1));

}
