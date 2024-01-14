#include "Sample.h"

//GAMECORE(Sample)
GAMECORE(sample,1024,768)


bool Sample::Init()
{
    
    m_Line.SetPosition(TVector3(0.0f, 0.0f, 0.0f));
    if (!m_Line.Create(m_pImmediateContext, L"", L"", L"LineShader.hlsl"))
    {
        return false;
    }

    m_Box.SetPosition(TVector3(0.0f, 0.0f, 0.0f));
    m_Box.Create(m_pImmediateContext, L"../../Data/object/metal.bmp", L"", L"Box.hlsl");

    m_Skybox.Init();
    m_Skybox.Create(m_pImmediateContext, L"../../Data/object/Sky/xxx.bmp", L"", L"SkyShader.hlsl");

    m_Camera.CreateViewMatrix(TVector3(0.0f, 5.0f, 0.0f), TVector3(0.0f, 0.0f, 0.0f));
    m_Camera.CreateProjMatrix(1.0f, 3000.0f, TBASIS_PI * 0.5f, (float)g_rtClient.right / (float)g_rtClient.bottom);
    m_Camera.m_pSpeed = 5.0f;
   
    return true;
}

bool Sample::Frame()
{
    
    return true;
}

bool Sample::Render()
{
    m_Skybox.m_matViewSky = m_Camera.m_matView;
    m_Skybox.m_matViewSky._41 = 0;
    m_Skybox.m_matViewSky._42 = 0;
    m_Skybox.m_matViewSky._43 = 0;
    TMatrix Scale, Rotation;
    TMatrix RetScale;
    Rotation.CreateRotationY(g_fGameTimer * 0.00f);
    D3DXMatrixScaling(&RetScale, 3000.0f, 3000.0f, 3000.0f);
    m_Skybox.m_matWorld = RetScale * Rotation;
    m_Skybox.SetMatrix(&m_Skybox.m_matWorld, &m_Skybox.m_matViewSky, &m_Camera.m_matProjection);
    m_Skybox.Render(m_pImmediateContext);

    m_Box.SetMatrix(nullptr, &m_Camera.m_matView, &m_Camera.m_matProjection);
    m_Box.Render(m_pImmediateContext);

    m_Line.SetMatrix(nullptr, &m_Camera.m_matView, &m_Camera.m_matProjection);
    m_Line.Render(m_pImmediateContext);
    
    return true;
}

bool Sample::Release()
{
   
    return true;
}


bool Sample::PreRender()
{
    float ClearColor[4] = { 0.0f, 0.1f, 0.3f, 1.0f };
    m_pImmediateContext->ClearRenderTargetView(m_DefaultRT.m_pRenderTargetView, ClearColor);
    m_pImmediateContext->ClearDepthStencilView(m_DefaultDS.m_pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    m_pImmediateContext->OMSetRenderTargets(1, &m_DefaultRT.m_pRenderTargetView, m_DefaultDS.m_pDepthStencilView);

    m_pImmediateContext->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINELIST);

    m_pImmediateContext->PSSetSamplers(0, 1, &DxState::g_pWrapSS);
    m_pImmediateContext->OMSetDepthStencilState(DxState::g_pLessEqualDSS, 0x01);

    return true;
}
