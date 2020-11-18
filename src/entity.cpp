#include "../headers/Entity.h"
#include <raylib.h>


Entity::Entity(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: position(_position), id(_id), rotation(0), speed(_speed), scale(_scale), spriteRect(_spriteRect), texture(_texture)
{
	hitboxRect = Rectangle(spriteRect);
	hitboxRect.width *= scale;
	hitboxRect.height *= scale;
}

void Entity::OnCreate() {}

void Entity::OnDestroy() {}

void Entity::Draw() 
{
	hitboxRect.x = position.x;
	hitboxRect.y = position.y;
	DrawTexturePro(texture, spriteRect, hitboxRect, {0,0}, rotation, WHITE);
}

void Entity::Update() 
{
	hitboxRect.x = position.x;
	hitboxRect.y = position.y;
}