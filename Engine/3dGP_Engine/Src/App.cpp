#include "Precompiled.h"
// ^^ put this at top of ALL cpp files

#include "App.h"

using namespace ChungusEngine;

void App::Run(const AppConfig& config)
{
	LOG("App Started");

	// inintialize all singletons and window
	Window myWindow;
	myWindow.Initialize(
		GetModuleHandle(nullptr),
		config.appName,
		config.winWidth,
		config.winHeight
	);

	// inintialize starting state

	// updates
	mIsRunning = true;
	while (mIsRunning)
	{
		myWindow.ProcessMessage();
		// updating all that needs updates
		if (!myWindow.IsActive())
		{
			Quit();
			continue;
		}
	}

	LOG("App Is Terminating");
	//terminate last state

	//terminate all singletons
	myWindow.Terminate();

}

void App::Quit()
{
	mIsRunning = false;
}