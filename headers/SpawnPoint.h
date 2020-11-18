#pragma once
#include <raylib.h>
#include "Entity.h"

class SpawnPoint : Entity
{
public:
	SpawnPoint() = default;
	SpawnPoint(Vector2 _position, int _id, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);
	void Update();
};
