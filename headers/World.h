#pragma once
#include "EntityManager.h"

class World
{
public :
	
	World();
	
	Shader bloom;
	Shader fishEye;

	EntityManager entityManager;
	RenderTexture renderTexture;



	void LoadResources();
	void UnloadResources();
	void Update();
	void Debug();

};

