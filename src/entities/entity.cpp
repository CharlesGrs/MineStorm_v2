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

		Color c = isColliding ? RED : GREEN;
		for (std::list<Vector2>::iterator it = hitbox.vertices.begin(); it != hitbox.vertices.end(); ++it) {
			i++;
			if (i > size - 1)
				DrawLineEx(Vector2{ it->x + position.x - origin.x, it->y + position.y - origin.y },
					Vector2{ hitbox.vertices.front().x + position.x - origin.x, hitbox.vertices.front().y + position.y - origin.y }, 3, c);
			else
				DrawLineEx(Vector2{ it->x + position.x - origin.x, it->y + position.y - origin.y },
					Vector2{ std::next(it)->x + position.x - origin.x, std::next(it)->y + position.y - origin.y },
					3, c);
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
		Cell* currentCell = Game::physics2D()->FindCellAtPos(position);

		if (Master::debugMode)
			DrawRectangleLines(currentCell->position.x, currentCell->position.y, Physics2D::cellSize, Physics2D::cellSize, WHITE);

		bool collided = false;
		for (Cell* c : currentCell->neighborCells)
		{
			for (Entity* e : c->entities)
			{
				if (e != this)
				{
					isColliding = CollisionSAT(hitbox, e->hitbox);
					collided = isColliding;
				}
			}
		}
		
		isColliding = collided;
	}

}

