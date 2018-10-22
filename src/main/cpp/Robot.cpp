/* 10/7/2018 Program:This project was derived from Robot_Framework_Ref2_2018
* (workspace: workspace2018_2) using 2018 FRC Framework on del's computer.
*
*  Path: C:/Users/Don Lauffer/2019_SingleMotor_VScode3/2019_SingleMotor2
*
*  This simple project controls a single motor using a TalonSRX motor controller. It requires:
*  	- a single TalonSRX motorcontroller connected to CAN IO 1
*  	- motor
*  	- a Logitech joystick to control speed and direction of motor connected to the DriverStation
*  	It can execute an autonomous routine in the AutonomousCommand.cpp file (currently a NOP).
*  	It is a TimedRobot command project that implements the IterativeRobotBase
*
*   The program did build without a problem using the cross compiler in Eclipse's IDE 10/9/2018
*
*  del
*
*/
#include "Robot.h"

//#include "OI.h" // appears that #include must be put in both this file and Robot.h?

// 	static smart pointers to provide access to the various Commands,
//  e.g., see: Requires(Robot::driveTrain.get()); and Robot::driveTrain->GetFL_MotorCurrent();

	std::unique_ptr<OI> Robot::oi;
	std::shared_ptr<MotorCntrl> Robot::mtrCntrl;

void Robot::RobotInit() {
	RobotMap::init();

//	Create an instance of Subsystem - will get an error until the Subsystem classes are created in a Subsystems file
//  reset(p) deletes previous ptr (if there is one) and acquires new ptr to object, e.g., a pointer to DriverTrain()
//  reset is a member function of shared_ptr therefore accessing it is done by the . access operator, not ->
//  both, e.g., driverTrain and reset are of the same type.  The same relation is true for the get function
//  since it is also a member of shared_ptr, i.e., shared_ptr::get()
//  This form of initialization is okay: std::shared_ptr<DriverTrain> driverTrain(new DriverTrain); , but
//  using reset() deletes ptr and object then resets a new ptr to an object.
//	Note: std::shared_ptr<DriverTrain>driverTrain = std::make_shared<DriverTrain>(); is a C++11 version -
// 	it compiles and could be used.

//  static smart pointers to objects of classes defined here
	mtrCntrl.reset(new MotorCntrl());
	oi.reset(new OI());

// instantiate the command used for the autonomous period
	autonomousCommand.reset(new AutonomousCommand()); // where AutonomousCommand() is a Command class
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

void Robot::AutonomousInit() {  // supply methods and set variables to initiate autonomous period
//  Set Autonomous Rountine with Drive Station DB/Buttons

	std::string m_gameData;
	m_gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if(m_gameData[0] == 'L') {
		printf("Left Side 1st Switch \n");
	}
	else  {
		printf("Right Side 1st Switch \n");
	}
	if(m_gameData[1] == 'L') {
		printf("Left Side Scaler \n");
	}
	else  {
		printf("Right Side Scaler \n");
	}

	GetButtonAuto();
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();  // set autonomous into Scheduler to run autonomous period
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run(); // Set teleop into Scheduler to run teleopPeriod
}

void Robot::TestPeriodic() {  // used LiveWindows when in Driver Station Test Mode
	//lw->Run();
}


//  Function to get DB/Buttons from Driver Station to run specific autonomous routines
void Robot::GetButtonAuto() {// method to select autonomous function
	int bval = 0;
	bool buttonstate = false;

	buttonstate = SmartDashboard::GetBoolean("DB/Button 0",false);
	if(buttonstate == true) bval |= 1;

	buttonstate = SmartDashboard::GetBoolean("DB/Button 1",false);
	if(buttonstate == true) bval |= 2;

	buttonstate = SmartDashboard::GetBoolean("DB/Button 2",false);
	if(buttonstate == true) bval |= 4;

	buttonstate = SmartDashboard::GetBoolean("DB/Button 3",false);
	if(buttonstate == true) bval |= 8;

	switch(bval)
	{
		case 0:
		{
			autonomousCommand.reset(new AutonomousCommand() );
		}
		break;
		case 1:
		{
			autonomousCommand.reset(new AutonomousNoOp());
		}
		break;

//Add other autonomous commands as needed here

		default:
		{
			autonomousCommand.reset(new AutonomousNoOp());
		}
		break;
	}
	return;
}


START_ROBOT_CLASS(Robot);

