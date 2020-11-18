#include "../headers/Entity.h"
#include <raylib.h>


Entity::Entity(Vector2 _position, float _speed, Rectangle _spriteRect, Texture2D _texture)
	: position(_position), rotation(0), speed(_speed), spriteRect(_spriteRect), texture(_texture)
{
	hitboxRect = spriteRect;
	hitboxRect.width /= 4;
	hitboxRect.height /= 4;
}

void Entity::OnCreate() {}

void Entity::OnDestroy() {}

void Entity::Draw() 
{
	hitboxRect.x = position.x;
	hitboxRect.y = position.y;
	DrawTexturePro(texture, spriteRect, hitboxRect, {0,0}, rotation, WHITE);
	//DrawTextureRec(texture, spriteRect, position, WHITE);
}

void Entity::Update() {}