#include "../headers/Entity.h"
#include <raylib.h>


Entity::Entity(Vector2 _position, float _speed, Rectangle _spriteRect, Texture2D _texture)
	: position(_position), rotation(0), speed(_speed), spriteRect(_spriteRect), texture(_texture)
{
}

void Entity::OnCreate() {}

void Entity::OnDestroy() {}

void Entity::Draw() 
{
	Color c;
	c.r = 1;
	c.g = 1;
	c.b = 1;
	c.a = 1;
	DrawTextureRec(texture, spriteRect, position, c);
}

void Entity::Update() {}