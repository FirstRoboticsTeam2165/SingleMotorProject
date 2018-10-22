

#pragma once


#include "Commands/Command.h"
//#include "../Robot.h"
//#include "WPILib.h"
/**
 *
 *
 * @author del
 */
class AutonomousCommand: public Command {
public:

	AutonomousCommand();


	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};
