#pragma once
#include <ChungusEngine.h>

class GameState : public ChungusEngine::AppState
{
public:
    void Initialize() override;
    void Update(float deltaTime) override;
    void Terminate() override;
};