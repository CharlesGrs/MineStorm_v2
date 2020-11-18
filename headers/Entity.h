#pragma once
#include <raylib.h>

class Entity
{
public :

	Entity() = default;
	Entity(Vector2 _position,int _id, float _speed, float scale,  Rectangle _spriteRect, Texture2D _texture);
	Vector2 position;
	float rotation = 0;
	float scale;
	float speed;
	int id;
	Vector2 origin;
	Rectangle spriteRect;
	Rectangle hitboxRect;
	Texture2D texture;

	void OnCreate();

	void OnDestroy();

	void Update();

	void Draw();
};