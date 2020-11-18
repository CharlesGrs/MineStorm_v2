#pragma once
#include <raylib.h>

class SpriteHelper
{
public:

	static Rectangle GetSpriteRectangle(Texture2D texture, int columnCount, int rowCount, int spriteIndex);
	static Vector2 GetSpriteOrigin(Rectangle spriteRect, float scale);
};