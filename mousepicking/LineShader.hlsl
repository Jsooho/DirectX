Texture2D g_txDiffuse : register(t0);
SamplerState g_Sampler : register(s0);

cbuffer cbData : register(b0)
{
	matrix g_matWorld	: packoffset(c0);
	matrix g_matView	: packoffset(c4);
	matrix g_matProj	: packoffset(c8);
	float  g_fTimer : packoffset(c12.z);
};

struct VS_IN
{
	float3 p : POSITION;
	float4 c : COLOR;
};
struct VS_OUT
{
	float4 p : SV_POSITION;
	float4 c : COLOR0;
};
VS_OUT VS(VS_IN vIn)
{
	VS_OUT output = (VS_OUT)0;
	float4 vLocal = float4(vIn.p, 1.0f);
	float4 vWorld = mul(vLocal, g_matWorld);
	float4 vView = mul(vWorld, g_matView);
	float4 vProj = mul(vView, g_matProj);
	output.p = vProj;
	output.c = vIn.c;

	return output;
}
float4 PS(VS_OUT v) : SV_TARGET
{
	return v.c;
}