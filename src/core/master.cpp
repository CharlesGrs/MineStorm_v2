#include "..\..\headers\core\Master.h"
#include "..\..\headers\core\Game.h"
#include "..\..\headers\core\Menu.h"
#include <string>

bool Master::debugMode;


Master::Master()
{
	LoadResources();
	ChangeScene(SceneIndex::Game);
}

Master::~Master()
{
	std::cout << "Unload Master \n";
	delete currentScene;
	UnloadResources();
}

void Master::ChangeScene(SceneIndex sceneIndex)
{
	delete currentScene;
	switch (sceneIndex)
	{
	case SceneIndex::Game:
		currentScene = new Game();
		break;
	case SceneIndex::Menu:
		currentScene = new Menu();
		break;
	}
}

void Master::Update()
{
	BeginDrawing();

	if (enableShader)
	{
		BeginTextureMode(renderTexture);
	}
	ClearBackground(BLACK);

	if (currentScene)
		currentScene->Update();

	if (enableShader)
	{
		EndTextureMode();

		BeginShaderMode(bloom);
		Rectangle renderTextureRect = { 0,0, renderTexture.texture.width, -renderTexture.texture.height };
		Vector2 zero = { 0, 0 };
		DrawTextureRec(renderTexture.texture, renderTextureRect, zero, WHITE);
		EndShaderMode();

		DrawRectangle(0, 0, 50, 50, BLACK);
		DrawRectangle(windowWidth - 50, 0, 50, 50, BLACK);
		DrawRectangle(windowWidth - 50, windowHeight - 50, 50, 50, BLACK);
		DrawRectangle(0, windowHeight - 50, 50, 50, BLACK);
	}

	if (IsKeyReleased(KEY_F1))
		enableShader = !enableShader;
	if (enableShader)
		DrawText("Press F1 to disable shaders", 5, windowHeight - 15, 12, WHITE);
	else
		DrawText("Press F1 to enable shaders", 5, windowHeight - 15, 12, WHITE);

	if (IsKeyReleased(KEY_F2))
		debugMode = !debugMode;
	if (debugMode)
		DrawText("Press F2 to disable debugMode", 5, windowHeight - 25, 12, WHITE);
	else
		DrawText("Press F2 to enable debugMode", 5, windowHeight - 25, 12, WHITE);


	int size = (int)Game::entityManager()->entityAmount();
	std::string s = "Entity count: " + std::to_string(size);
	char const* pChar = s.c_str();
	DrawText(pChar, 5, 10, 12, WHITE);
	EndDrawing();
}

void Master::LoadResources()
{
	bloom = LoadShader(0, "assets/shaders/bloom.fs");
	renderTexture = LoadRenderTexture(Master::windowWidth, Master::windowHeight);
}

void Master::UnloadResources()
{
	UnloadShader(bloom);
	UnloadRenderTexture(renderTexture);
}
