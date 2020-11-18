#pragma once
#include <raylib.h>
#include "Entity.h"

class MineLayer : Entity
{
public:
	MineLayer() = default;
	MineLayer(Vector2 _position, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);
};
