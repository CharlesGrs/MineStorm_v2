#pragma once
#include <raylib.h>
#include "../core/Scene.h"

enum class  SceneIndex {
	Menu,
	Game,
};
class Master
{
private: 
public:
	Master();
	~Master();

	static Master* instance;

	bool enableShader = true;
	static bool debugMode;
	Shader bloom;
	RenderTexture renderTexture;
	Scene* currentScene;
	static const int windowWidth = 1080;
	static const int windowHeight = 720;

	void ChangeScene(SceneIndex scene, bool twoPlayers = false);
	void Update();
	void LoadResources();
	void UnloadResources();
};