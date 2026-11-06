#include <ChungusEngine.h>
#include "DoSomethingState.h"
#include "DoColorState.h"
#include "DoTriforceState.h"
#include "DoStarState.h"
#include "DoHeartState.h"

int WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
    ChungusEngine::AppConfig config;
    config.appName = L"Hello Shapes";

    ChungusEngine::App& myApp = ChungusEngine::MainApp();
    myApp.AddState<DoSomethingState>("DoSomethingState");
    myApp.AddState<DoColorState>("DoColorState");
    myApp.AddState<DoTriforceState>("DoTriforceState");
    myApp.AddState<DoStarState>("DoStarState");
    myApp.AddState<DoHeartState>("DoHeartState");
    myApp.Run(config);
    return 0;
}