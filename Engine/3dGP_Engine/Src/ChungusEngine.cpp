#include "Precompiled.h"
#include "ChungusEngine.h"

ChungusEngine::App& ChungusEngine::MainApp()
{
	static App sApp;
	return sApp;
}