#include "..\..\headers\core\Menu.h"
#include "..\..\headers\core\Master.h"
#include <raylib.h>


float blinkTimer;
void Menu::Update()
{
	blinkTimer += GetFrameTime();
	if (blinkTimer < 0.5f)
		DrawText("MINESTORM", Master::windowWidth / 2 - 150, 50, 50, SKYBLUE);
	else if (blinkTimer > 1)
		blinkTimer = 0;

	DrawText("ONE PLAYER -> PRESS Z", Master::windowWidth / 2 - 200, 150, 30, SKYBLUE);
	DrawText("TWO PLAYERS -> PRESS I", Master::windowWidth / 2 - 200, 190, 30, SKYBLUE);

	if (IsKeyPressed(KEY_W)) {
		Master::instance->ChangeScene(SceneIndex::Game, false);
	}
	else if (IsKeyPressed(KEY_I)) {
		Master::instance->ChangeScene(SceneIndex::Game, true);
	}

}
