#include "DoColorState.h"

using namespace ChungusEngine::Graphics;
using namespace ChungusEngine::Input;

void DoColorState::Initialize()
{
	// setup camera
	mCamera.SetPosition({ 0.f, 1.f, -3.f });
	mCamera.SetLookAt({ 0.f, 0.f, 0.f });

	// create a cube
	// have 6 sides
	// each side is 2 triangles
	// each triangle is 3 vertices
	// vertices must be in clockwise order

	// front
	mVertices.push_back({ { -1.0f, -1.0f, -1.0f }, Colors::Red });
	mVertices.push_back({ { -1.0f,  1.0f, -1.0f }, Colors::Red });
	mVertices.push_back({ {  1.0f,  1.0f, -1.0f }, Colors::Red });

	mVertices.push_back({ { -1.0f, -1.0f, -1.0f }, Colors::Blue });
	mVertices.push_back({ {  1.0f,  1.0f, -1.0f }, Colors::Blue });
	mVertices.push_back({ {  1.0f, -1.0f, -1.0f }, Colors::Blue });

	// right
	mVertices.push_back({ {  1.0f, -1.0f, -1.0f }, Colors::Green });
	mVertices.push_back({ {  1.0f,  1.0f, -1.0f }, Colors::Green });
	mVertices.push_back({ {  1.0f,  1.0f,  1.0f }, Colors::Green });

	mVertices.push_back({ {  1.0f, -1.0f, -1.0f }, Colors::Purple });
	mVertices.push_back({ {  1.0f,  1.0f,  1.0f }, Colors::Purple });
	mVertices.push_back({ {  1.0f, -1.0f,  1.0f }, Colors::Purple });
	// left
	mVertices.push_back({ { -1.0f, -1.0f,  1.0f }, Colors::Yellow });
	mVertices.push_back({ { -1.0f,  1.0f,  1.0f }, Colors::Yellow });
	mVertices.push_back({ { -1.0f,  1.0f, -1.0f }, Colors::Yellow });

	mVertices.push_back({ { -1.0f, -1.0f,  1.0f }, Colors::Orange });
	mVertices.push_back({ { -1.0f,  1.0f, -1.0f }, Colors::Orange });
	mVertices.push_back({ { -1.0f, -1.0f, -1.0f }, Colors::Orange });

	// back
	mVertices.push_back({ {  1.0f, -1.0f,  1.0f }, Colors::Cyan });
	mVertices.push_back({ {  1.0f,  1.0f,  1.0f }, Colors::Cyan });
	mVertices.push_back({ { -1.0f,  1.0f,  1.0f }, Colors::Cyan });

	mVertices.push_back({ {  1.0f, -1.0f,  1.0f }, Colors::Magenta });
	mVertices.push_back({ { -1.0f,  1.0f,  1.0f }, Colors::Magenta });
	mVertices.push_back({ { -1.0f, -1.0f,  1.0f }, Colors::Magenta });

	// top
	mVertices.push_back({ { -1.0f,  1.0f, -1.0f }, Colors::White });
	mVertices.push_back({ { -1.0f,  1.0f,  1.0f }, Colors::White });
	mVertices.push_back({ {  1.0f,  1.0f,  1.0f }, Colors::White });

	mVertices.push_back({ { -1.0f,  1.0f, -1.0f }, Colors::Gray });
	mVertices.push_back({ {  1.0f,  1.0f,  1.0f }, Colors::Gray });
	mVertices.push_back({ {  1.0f,  1.0f, -1.0f }, Colors::Gray });

	// bottom
	mVertices.push_back({ {  1.0f, -1.0f, -1.0f }, Colors::Black });
	mVertices.push_back({ {  1.0f, -1.0f,  1.0f }, Colors::Black });
	mVertices.push_back({ { -1.0f, -1.0f,  1.0f }, Colors::Black });

	mVertices.push_back({ {  1.0f, -1.0f, -1.0f }, Colors::Pink });
	mVertices.push_back({ { -1.0f, -1.0f,  1.0f }, Colors::Pink });
	mVertices.push_back({ { -1.0f, -1.0f, -1.0f }, Colors::Pink });


	mMeshBuffer.Initialize(mVertices.data(), sizeof(VertexPC), mVertices.size());
	std::filesystem::path shaderPath = L"../../Assets/Shaders/DoTransform.fx";
	mVertexShader.Initialize<VertexPC>(shaderPath);
	mPixelShader.Initialize(shaderPath);

	mTransformBuffer.Initialize(sizeof(Math::Matrix4));
}
void DoColorState::Update(float deltaTime)
{
	InputSystem* input = InputSystem::Get();
	const float moveSpeed = (input->IsKeyDown(KeyCode::LSHIFT)) ? 10.0f : 1.0f;
	const float turnSpeed = 0.1f;
	if (input->IsKeyDown(KeyCode::W))
	{
		mCamera.Walk(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::S))
	{
		mCamera.Walk(-moveSpeed * deltaTime);
	}
	if (input->IsKeyDown(KeyCode::D))
	{
		mCamera.Strafe(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::A))
	{
		mCamera.Strafe(-moveSpeed * deltaTime);
	}
	if (input->IsKeyDown(KeyCode::E))
	{
		mCamera.Rise(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::Q))
	{
		mCamera.Rise(-moveSpeed * deltaTime);
	}
	if (input->IsMouseDown(MouseButton::RBUTTON))
	{
		mCamera.Yaw(input->GetMouseMoveX() * turnSpeed * deltaTime);
		mCamera.Pitch(input->GetMouseMoveY() * turnSpeed * deltaTime);
	}
}
void DoColorState::Render()
{
	mVertexShader.Bind();
	mPixelShader.Bind();
	mTransformBuffer.BindVS(0);

	// update buffer data
	Math::Matrix4 matWorld = Math::Matrix4::Identity;
	Math::Matrix4 matView = mCamera.GetViewMatrix();
	Math::Matrix4 matProj = mCamera.GetProjectionMatrix();
	Math::Matrix4 matFinal = matWorld * matView * matProj;
	Math::Matrix4 wvp = Math::Transpose(matFinal);
	mTransformBuffer.Update(&wvp);

	mMeshBuffer.Render();
}
void DoColorState::Terminate()
{
	mVertices.clear();
	mPixelShader.Terminate();
	mVertexShader.Terminate();
	mMeshBuffer.Terminate();
	mTransformBuffer.Terminate();
}