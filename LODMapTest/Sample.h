#pragma once
#include<Core.h>
#include"HMap.h"
#include"Shape.h"
#include"Camera.h"
#include"Quadtree.h"

class Sample : public Core
{
public:
	
	//BoxShape m_BoxObj[2];
	HMap	m_Map;
	QuadTree m_Quadtree;
	//Texture m_Texture;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
	Sample();
	virtual ~Sample();
};

