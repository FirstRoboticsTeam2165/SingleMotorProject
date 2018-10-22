

#pragma once

#include "WPILib.h"

class OI {
private:
//  shared pointers to joysticks
	std::shared_ptr<Joystick> joystick0;

// shared pointers to joystick buttons
	std::shared_ptr<JoystickButton> joystick0_Button1;


// Joystick USB
	static constexpr int USB_0 = 0;

// Joystick Button Numbers
	static constexpr int BUTTON_1 = 1;   // Trigger


public:
	OI();
//declare method to provide public access to joysticks and buttons
	std::shared_ptr<Joystick> getJoystick0();
	std::shared_ptr<JoystickButton> getJoystick0_Button1();

};

