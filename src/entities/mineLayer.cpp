#include <raylib.h>
#include "../../headers/entities/MineLayer.h"

// Debug
#include <string>

MineLayer::MineLayer(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: Entity(_position, _id, _speed, _scale, _spriteRect, _texture)
{
}




