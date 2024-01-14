#pragma once
#include<Core.h>
#include"Shape.h"
#include"Skybox.h"
class Sample : public Core
{
public:
	BoxShape	m_Box;
	LineShape m_Line;
	Skybox		m_Skybox;

public:
	bool PreRender()override;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

