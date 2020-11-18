#pragma once
#include "EntityManager.h"

class World
{
public :
	
	World();
	
	Shader bloom;
	EntityManager entityManager;
	RenderTexture renderTexture;


	void LoadResources();
	void Update();
	void Debug();
};