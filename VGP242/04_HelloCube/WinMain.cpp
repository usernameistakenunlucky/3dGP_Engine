#include <ChungusEngine.h>
#include "DoColorState.h"

int WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
    ChungusEngine::AppConfig config;
    config.appName = L"Hello Shapes";

    ChungusEngine::App& myApp = ChungusEngine::MainApp();
    myApp.AddState<DoColorState>("DoColorState");
    myApp.Run(config);
    return 0;
}