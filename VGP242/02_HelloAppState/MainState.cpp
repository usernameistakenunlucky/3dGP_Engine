#include "MainState.h"

using namespace ChungusEngine::Input;
void MainState::Initialize()
{
    LOG("MAIN STATE INITIALIZED");
}
void MainState::Update(float deltaTime)
{
    if (InputSystem::Get()->IsKeyPressed(KeyCode::SPACE))
    {
        ChungusEngine::MainApp().ChangeState("GameState");
    }
}
void MainState::Terminate()
{
    LOG("MAIN STATE IS TERMINATED");
}