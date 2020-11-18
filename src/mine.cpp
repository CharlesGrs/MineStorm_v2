#include <raylib.h>
#include "../headers/Mine.h"


// Debug
#include <string>

Mine::Mine(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: Entity(_position, _id, _speed, _scale, _spriteRect, _texture)
{
}

Floating_Mine::Floating_Mine(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: Mine(_position, _id, _speed, _scale, _spriteRect, _texture)
{
}

Fireball_Mine::Fireball_Mine(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: Mine(_position, _id, _speed, _scale, _spriteRect, _texture)
{
}

Magnetic_Mine::Magnetic_Mine(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: Mine(_position, _id, _speed, _scale, _spriteRect, _texture)
{
}

Magnetic_Fireball_Mine::Magnetic_Fireball_Mine(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: Mine(_position, _id, _speed, _scale, _spriteRect, _texture)
{
}




