#pragma once

#include "Commands/Command.h"
//#include "../Robot.h"
//#include "WPILib.h"

/**
 *
 *
 * @author del
 */
class AutonomousNoOp : public Command {
public:
	AutonomousNoOp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


