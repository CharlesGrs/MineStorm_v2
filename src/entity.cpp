#include "../headers/SpriteHelper.h"
#include "../headers/World.h"
#include <raylib.h>


Entity::Entity(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: position(_position), id(_id), rotation(0), speed(_speed), scale(_scale), spriteRect(_spriteRect), texture(_texture)
{
	hitboxRect = Rectangle(spriteRect);
	hitboxRect.width *= scale;
	hitboxRect.height *= scale;

	origin = SpriteHelper::GetSpriteOrigin(spriteRect, scale);
}

void Entity::OnCreate() {}

void Entity::OnDestroy() {}

void Entity::Draw() 
{
	hitboxRect.x = position.x;
	hitboxRect.y = position.y;
	DrawTexturePro(texture, spriteRect, hitboxRect, origin, rotation, WHITE);
}

void Entity::Update() 
{

	if (position.x > World::windowWidth)
		position.x = 0;
	else if (position.y > World::windowHeight)
		position.y = 0;
	
	if (position.y < 0)
		position.y = World::windowHeight;
	else if (position.x < 0)
		position.x = World::windowWidth;

	hitboxRect.x = position.x;
	hitboxRect.y = position.y;
}