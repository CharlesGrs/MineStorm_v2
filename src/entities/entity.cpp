#include <raylib.h>
#include "../../headers/helpers/SpriteHelper.h"
#include "../../headers/core/Game.h"
#include "../../headers/core/Master.h"
#include "../../headers/gameplay/Physics2D.h"
#include "../../headers/helpers/Vector2Helper.h"

Entity::Entity(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Polygon _hitbox, Texture2D _texture)
	: position(_position), rotation(0), speed(_speed), scale(_scale), spriteRect(_spriteRect), hitbox(_hitbox), texture(_texture)
{
	hitboxRect = Rectangle(spriteRect);
	hitboxRect.width *= scale;
	hitboxRect.height *= scale;

	origin = SpriteHelper::GetSpriteOrigin(spriteRect, scale);
}

void Entity::Draw()
{
	hitboxRect.x = position.x;
	hitboxRect.y = position.y;
	DrawTexturePro(texture, spriteRect, hitboxRect, origin, rotation, Color{ 120,200,255 ,255 });

	if (Master::debugMode)
	{
		int size = hitbox.vertices.size();
		int i = 0;
		for (std::list<Vector2>::iterator it = hitbox.vertices.begin(); it != hitbox.vertices.end(); ++it) {
			i++;
			if (i > size - 1)
				DrawLineEx(Vector2{ it->x + position.x - origin.x, it->y + position.y - origin.y },
					Vector2{ hitbox.vertices.front().x + position.x - origin.x, hitbox.vertices.front().y + position.y - origin.y }, 3, GREEN);
			else
				DrawLineEx(Vector2{ it->x + position.x - origin.x, it->y + position.y - origin.y }, 
					Vector2{ std::next(it)->x + position.x - origin.x, std::next(it)->y + position.y - origin.y },
					3, GREEN);
		}
	}
}

void Entity::RotateHitbox(float angle)
{
	for (std::list<Vector2>::iterator it = hitbox.vertices.begin(); it != hitbox.vertices.end(); ++it)
	{
		Vector2 newPoint = Vector2Helper::RotatePoint(origin.x, origin.y, angle * DEG2RAD, Vector2{ it->x, it->y });
		it->x = newPoint.x;
		it->y = newPoint.y;
	}
}

void Entity::Update()
{

	if (position.x > Master::windowWidth)
		position.x = 0;
	else if (position.y > Master::windowHeight)
		position.y = 0;

	if (position.y < 0)
		position.y = Master::windowHeight;
	else if (position.x < 0)
		position.x = Master::windowWidth;

	hitboxRect.x = position.x;
	hitboxRect.y = position.y;

	

	if (enablePhysics)
	{
		bool checkX = position.x >= 0 && position.x < Master::windowWidth;
		bool checkY = position.y >= 0 && position.y < Master::windowHeight;

		Cell newCell = currentCell;

		if (checkX && checkY)
			newCell = Physics2D::instance()->FindCellAtPos(position);

		if ((newCell.position.x != currentCell.position.x) || (newCell.position.y != currentCell.position.y))
		{
 			currentCell.RemoveEntity(this);
			currentCell = newCell;
			currentCell.AddEntity(this);
		}

		//Physics2D::instance()->DrawGrid();
		DrawRectangleLines(currentCell.position.x, currentCell.position.y, Physics2D::instance()->cellSize, Physics2D::instance()->cellSize, WHITE);
		

		std::list<Entity*> temp = Physics2D::instance()->GetEntityInNeighborCells(currentCell);
		for (Entity* e : temp)
		{
			//check collision
		}
	}

}

