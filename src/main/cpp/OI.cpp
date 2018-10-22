
#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"

// add #include files for commands that you create
#include "Commands/RunMotorJoystick.h"
#include "Commands/AutonomousCommand.h"




OI::OI() {
    // Assign joystick pointer to an instance of the Joystick( ) class

    joystick0.reset(new Joystick(USB_0));  // Logitech assigned to motor joystick0

    // Assign joystickbutton pointers to buttons on joystick

    joystick0_Button1.reset(new JoystickButton(joystick0.get(), BUTTON_1));


    // SmartDashboard Buttons
    SmartDashboard::PutData("Motor Joystick", new RunMotorJoystick());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

}

	std::shared_ptr<Joystick> OI::getJoystick0() {return joystick0;}
	std::shared_ptr<JoystickButton> OI::getJoystick0_Button1() {return joystick0_Button1;}

