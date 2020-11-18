#include <raylib.h>
#include "../headers/SpriteHelper.h"


Rectangle SpriteHelper::GetSpriteRectangle(Texture2D texture, int columnCount, int rowCount, int spriteIndex){

	int width = texture.width;
	int height = texture.height;
	int spriteWidth = width / columnCount;
	int spriteHeight = height / rowCount;
	int spriteCount = columnCount * rowCount;

	int xIndex = columnCount - rowCount;
	int yIndex = spriteIndex - xIndex * columnCount;

	Rectangle spriteRect;
	spriteRect.width = spriteWidth;
	spriteRect.height = spriteWidth;
	spriteRect.x = xIndex * spriteHeight;
	spriteRect.y = yIndex * spriteWidth;
}