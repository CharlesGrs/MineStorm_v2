#pragma once
#include <raylib.h>

class Entity
{
public :

	Entity() = default;
	Entity(Vector2 _position, float _speed, Rectangle _spriteRect, Texture2D _texture) ;
	Vector2 position;
	float rotation = 0;
	float speed;
	Rectangle spriteRect;
	Texture2D texture;

	virtual void OnCreate();

	virtual void OnDestroy();

	virtual void Update();

	virtual void Draw();
};