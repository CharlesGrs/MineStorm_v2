#pragma once
#include <raylib.h>
#include "../headers/Entity.h"

class MineLayer : Entity
{
public:
	MineLayer() = default;
	MineLayer(Vector2 _position, int _id, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);
	void Update() {};
};
