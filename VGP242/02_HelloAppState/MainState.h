#pragma once
#include <ChungusEngine.h>


class MainState : public ChungusEngine::AppState
{
public:
    void Initialize() override;
    void Update(float deltaTime) override;
    void Terminate() override;
};