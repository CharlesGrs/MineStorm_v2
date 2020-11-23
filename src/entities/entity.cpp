#include <raylib.h>
#include "../../headers/helpers/SpriteHelper.h"
#include "../../headers/core/Game.h"
#include "../../headers/core/Master.h"
#include "../../headers/gameplay/Physics2D.h"
#include "../../headers/helpers/Vector2Helper.h"

Entity::Entity(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Hitbox _hitbox, Texture2D _texture)
	: position(_position), rotation(0), speed(_speed), scale(_scale), spriteRect(_spriteRect), hitbox(_hitbox), texture(_texture)
{
	drawRect = Rectangle(spriteRect);
	drawRect.width *= scale;
	drawRect.height *= scale;

	origin = SpriteHelper::GetSpriteOrigin(spriteRect, scale);
}

void Entity::Draw()
{
	drawRect.x = position.x;
	drawRect.y = position.y;
	DrawTexturePro(texture, spriteRect, drawRect, origin, rotation, Color{ 120,200,255 ,255 });
	if (Master::debugMode)
	{
		Color c = isColliding ? RED : GREEN;
		if (hitbox.type == HitboxType::Polygon)
		{
			Polygon* polygon = (Polygon*)(hitbox.shape);
			int size = polygon->vertices.size();
			int i = 0;
			for (std::list<Vector2>::iterator it = polygon->vertices.begin(); it != polygon->vertices.end(); ++it) {
				i++;
				if (i > size - 1)
					DrawLineEx(Vector2{ it->x + position.x - origin.x, it->y + position.y - origin.y },
						Vector2{ polygon->vertices.front().x + position.x - origin.x, polygon->vertices.front().y + position.y - origin.y }, 3, c);
				else
					DrawLineEx(Vector2{ it->x + position.x - origin.x, it->y + position.y - origin.y },
						Vector2{ std::next(it)->x + position.x - origin.x, std::next(it)->y + position.y - origin.y },
						3, c);
			}
		}
		else if (hitbox.type == HitboxType::Circle)
		{
			Circle* circle = (Circle*)(hitbox.shape);
			DrawCircleLines(position.x, position.y, circle->radius, c);
		}
	}
}

void Entity::RotateHitbox(float angle)
{
	if (hitbox.type != HitboxType::Polygon)
		return;

	Polygon* polygon = dynamic_cast<Polygon*>(hitbox.shape);
	for (std::list<Vector2>::iterator it = polygon->vertices.begin(); it != polygon->vertices.end(); ++it)
	{
		Vector2 newPoint = Vector2Helper::RotatePoint(origin.x, origin.y, angle * DEG2RAD, Vector2{ it->x, it->y });
		it->x = newPoint.x;
		it->y = newPoint.y;
	}
}

void Entity::Update()
{
	CheckBorder();
	CheckCollision();
}

void Entity::CheckBorder()
{
	if (position.x > Master::windowWidth)
		position.x = 0;
	else if (position.y > Master::windowHeight)
		position.y = 0;

	if (position.y < 0)
		position.y = Master::windowHeight;
	else if (position.x < 0)
		position.x = Master::windowWidth;
}

void Entity::CheckCollision()
{
	if (!enablePhysics)return;

	Cell* currentCell = Game::physics2D()->FindCellAtPos(position);

	bool collided = false;
	for (Cell* c : currentCell->neighborCells)
	{
		for (Entity* e : c->entities)
		{
			if (e != this)
			{
				if (hitbox.type == HitboxType::Polygon)
				{
					Polygon* polygon = (Polygon*)(hitbox.shape);

					if (e->hitbox.type == HitboxType::Polygon)
					{
						Polygon* polygon2 = (Polygon*)(e->hitbox.shape);
						if (position.x - origin.x  < e->position.x - e->origin.x + e->spriteRect.width * e->scale &&
							position.x - origin.x + spriteRect.width * scale > e->position.x - e->scale &&
							position.y - origin.x < e->position.y - e-> origin.y + e->spriteRect.height * e->scale &&
							position.y - origin.x + spriteRect.height * scale > e->position.y - e-> origin.y)
						{
							isColliding = Physics2D::CollisionSAT(polygon, polygon2, Vector2Helper::Substract(position, origin), Vector2Helper::Substract(e->position, e->origin));
							if (isColliding)
								collided = true;
						}
					}
					else
					{
						Circle* circle2 = (Circle*)(hitbox.shape);
						// isColliding =
					}
				}

				else
				{
					Circle* circle = (Circle*)(hitbox.shape);

					if (e->hitbox.type == HitboxType::Polygon)
					{
						Polygon* polygon2 = (Polygon*)(e->hitbox.shape);
						// isColliding =
					}
					else
					{
						Circle* circle2 = (Circle*)(hitbox.shape);
						// isColliding =
					}
				}
			}
		}
	}

	isColliding = collided;
}

