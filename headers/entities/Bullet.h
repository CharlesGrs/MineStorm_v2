#pragma once
#include <raylib.h>
#include "../../headers/entities/Entity.h"

class Bullet : public Entity
{
public :
	Vector2 velocity = {0,0};
	Bullet() = default;
	Bullet(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
		: Entity(_position, _speed, _scale, _spriteRect, _texture) {};
	~Bullet() {};


	void Update();
	void Draw();
	void UpdatePosition();

	Entity* Clone();

};