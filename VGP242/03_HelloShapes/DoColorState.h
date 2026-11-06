#pragma once

#include <ChungusEngine.h>

class DoColorState : public ChungusEngine::AppState
{
public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Terminate() override;
private:
	struct Vertex
	{
		ChungusEngine::Math::Vector3 position = ChungusEngine::Math::Vector3::Zero;
		ChungusEngine::Color color = ChungusEngine::Colors::White;
	};
	using Vertices = std::vector<Vertex>;
	Vertices mVertices;

	// our shape information
	ID3D11Buffer* mVertexBuffer = nullptr;
	// bind to the VS function
	ID3D11VertexShader* mVertexShader = nullptr;
	// tell vs the configuration of the vertex
	ID3D11InputLayout* mInputLayout = nullptr;
	// bind to the PS function
	ID3D11PixelShader* mPixelShader = nullptr;
};