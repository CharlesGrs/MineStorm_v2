#pragma once
#include <raylib.h>
#include "Entity.h"

class Bullet : Entity
{
public:
	Bullet() = default;
	Bullet(Vector2 _position, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);
};
