#include "Sample.h"
GAMECORE(SampleMap,800,600)

bool Sample::Init()
{
    m_Texture.LoadTexture(L"../../Data/object/bitmap1.BMP");
    //m_Texture.LoadTexture(L"../../Data/object/20200428_185613.jpg");
    MapInfo info{
            16 + 1,
            16 + 1, 0,0, 0,
            1.0f
    };
    if (!m_Map.Load(info, L"../../Data/Shader/DefaultShader.hlsl", L"../../Data/Shader/DefaultShader.hlsl"))
    {
        return false;
    }
    m_Quadtree.LoadObject(L"../../Data/Script/LOD.txt");
    m_Quadtree.Build(&m_Map);
    
    return true;
}
bool Sample::Frame()
{
    m_Map.Frame();
    return true;
}

bool Sample::Render()
{
    //m_pImmediateContext->PSSetSamplers(0, 1, &m_Texture.m_pSampler);
    m_pImmediateContext->PSSetShaderResources(1, 1, &m_Texture.m_pTextureSRV);
    m_Map.SetMatrix( nullptr, &m_Camera.m_matView, &m_Camera.m_matProjection);
    m_Quadtree.Render(m_pImmediateContext, &m_Camera);
    return true;
}

bool Sample::Release()
{
    
    m_Map.Release();
    m_Quadtree.Release();
    return true;
}

Sample::Sample()
{
}
Sample::~Sample()
{
}