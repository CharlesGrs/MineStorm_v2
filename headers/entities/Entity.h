#pragma once
#include <raylib.h>

class Entity
{
public:

	Entity() = default;
	Entity(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture);
	~Entity() = default; // VIRTUAL 

	Vector2 position;
	float rotation = 0;
	float scale;
	float speed;
	Vector2 origin;
	Rectangle spriteRect;
	Rectangle hitboxRect;
	Texture2D texture; //POINTER

	virtual void Update();
	virtual Entity* Clone() = 0;
	void Draw();
};