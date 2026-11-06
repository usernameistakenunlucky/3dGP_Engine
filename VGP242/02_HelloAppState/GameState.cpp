#include "GameState.h"

using namespace ChungusEngine::Input;
void GameState::Initialize()
{
    LOG("GAME STATE INITIALIZED");
}

void GameState::Update(float deltaTime)
{
    if (InputSystem::Get()->IsKeyPressed(KeyCode::SPACE))
    {
        ChungusEngine::MainApp().ChangeState("MainState");
    }
}

void GameState::Terminate()
{
    LOG("GAME STATE IS TERMINATED");
}