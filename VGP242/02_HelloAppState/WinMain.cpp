#include <ChungusEngine.h>
#include "MainState.h"
#include "GameState.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
    ChungusEngine::AppConfig config;
    config.appName = L"Hello App State";

    ChungusEngine::App& myApp = ChungusEngine::MainApp();
    myApp.AddState<MainState>("MainState");
    myApp.AddState<GameState>("GameState");
    myApp.Run(config);

    return 0;
}