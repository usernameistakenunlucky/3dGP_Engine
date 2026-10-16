#include <ChungusEngine.h>

using namespace ChungusEngine;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	AppConfig config;
	config.appName = L"Hello Window";

	App myApp;
	myApp.Run(config);

	return 0;
}