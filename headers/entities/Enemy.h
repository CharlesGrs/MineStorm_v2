#pragma once
#include <raylib.h>
#include "Entity.h"

class Enemy : public Entity
{
public:
	int score;

	Enemy() = default;
	Enemy(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Hitbox _hitbox, Texture2D _texture) :
		Entity(_position, _speed, _scale, _spriteRect, _hitbox, _texture)
	{
		enablePhysics = true;
		score = 0;
	}
	~Enemy() = default;
};