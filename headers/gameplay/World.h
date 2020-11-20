#pragma once
#include "EntityManager.h"

class World
{

private:
	static EntityManager* _eM;

public :
	
	World();
	~World();
	
	bool enableShader = true;
	static bool debugMode;
	Shader bloom;
	
	static EntityManager* entityManager()
	{
		if (_eM == NULL)
		{
			Texture spriteSheet = LoadTexture("assets/minestorm_sprite_atlas_mine_storm.png");
			_eM = new EntityManager(spriteSheet);
		}
		return _eM;
	}
	RenderTexture renderTexture;

	static const int windowWidth = 1080;
	static const int windowHeight = 720;

	void LoadResources();
	void UnloadResources();
	void Update();
	void Debug();
};

