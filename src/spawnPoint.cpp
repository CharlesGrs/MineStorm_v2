#include <raylib.h>
#include "../headers/SpawnPoint.h"


// Debug
#include <string>

SpawnPoint::SpawnPoint(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: Entity(_position, _id, _speed, _scale, _spriteRect, _texture)
{
}
