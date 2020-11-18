#pragma once
#include <raylib.h>
#include "Entity.h"

class Mine : Entity
{
public:
	Mine() = default;
	Mine(Vector2 _position, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);
};

class Floating_Mine : Mine
{
public:
	Floating_Mine() = default;
	Floating_Mine(Vector2 _position, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);
};

class Fireball_Mine : Mine
{
public:
	Fireball_Mine() = default;
	Fireball_Mine(Vector2 _position, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);
};

class Magnetic_Mine : Mine
{
public:
	Magnetic_Mine() = default;
	Magnetic_Mine(Vector2 _position, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);
};

class Magnetic_Fireball_Mine : Mine
{
public:
	Magnetic_Fireball_Mine() = default;
	Magnetic_Fireball_Mine(Vector2 _position, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);
};