#include <raylib.h>
#include "../headers/Bullet.h"

// Debug
#include <string>

Bullet::Bullet(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: Entity(_position, _speed, _scale, _spriteRect, _texture)
{
}
