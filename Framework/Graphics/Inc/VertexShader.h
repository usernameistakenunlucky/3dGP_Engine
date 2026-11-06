#pragma once

namespace ChungusEngine::Graphics
{
    class VertexShader final
    {
    public:
        template<class VertexTypes>
        void Initialize(const std::filesystem::path& shaderPath)
        {
            Initialize(shaderPath, VertexTypes::Format);
        }
        void Initialize(const std::filesystem::path& shaderPath, uint32_t format);
        void Terminate();
        void Bind();
    private:
        ID3D11VertexShader* mVertexShader = nullptr;
        ID3D11InputLayout* mInputLayout = nullptr;
    };
}