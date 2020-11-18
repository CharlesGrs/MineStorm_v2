#include <raylib.h>
#include "../headers/SpriteHelper.h"


/* 
Todo: Implement more generic method
*/
Rectangle SpriteHelper::GetSpriteRectangle(Texture2D texture, int columnCount, int rowCount, int spriteIndex)
{
	float width = texture.width;
	float height = texture.height;
	float spriteWidth = width / columnCount;
	float spriteHeight = height / rowCount;
	float spriteCount = columnCount * rowCount;

	//for now cause we only have 2 rows (and 4 columns), and spriteIndex starts at 0
	int xIndex = spriteIndex >= columnCount ? spriteIndex - columnCount : spriteIndex;
	int yIndex = spriteIndex >= columnCount ? 1 : 0;

	//int xIndex = columnCount - rowCount; //this is a const
	//int yIndex = spriteIndex - xIndex * columnCount; 

	Rectangle spriteRect;

	spriteRect.width = spriteWidth;
	spriteRect.height = spriteHeight;
	spriteRect.x = xIndex * spriteWidth;
	spriteRect.y = yIndex * spriteHeight;

	return spriteRect;
}