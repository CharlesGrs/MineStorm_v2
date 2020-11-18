#include <raylib.h>
#include "../headers/SpriteHelper.h"


Rectangle SpriteHelper::GetSpriteRectangle(Texture2D texture, int columnCount, int rowCount, int spriteIndex)
{
	float width = texture.width;
	float height = texture.height;
	float spriteWidth = width / columnCount;
	float spriteHeight = height / rowCount;
	int spriteCount = columnCount * rowCount;

	int xIndex = spriteIndex / spriteCount;
	int yIndex = spriteIndex % spriteCount;

	Rectangle spriteRect;

	spriteRect.width = spriteWidth;
	spriteRect.height = spriteHeight;
	spriteRect.x = xIndex * spriteWidth;
	spriteRect.y = yIndex * spriteHeight;

	return spriteRect;
}