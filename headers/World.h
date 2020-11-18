#pragma once
#include "EntityManager.h"

class World
{
public :
	
	World();
	~World() = default;
	
	Shader bloom;
	Shader fishEye;

	EntityManager entityManager;
	RenderTexture renderTexture;

	static const int windowWidth = 1080;
	static const int windowHeight = 720;



	void LoadResources();
	void UnloadResources();
	void Update();
	void Debug();

};

