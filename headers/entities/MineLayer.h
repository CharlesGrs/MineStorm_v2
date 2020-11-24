#pragma once
#include "Enemy.h"

class Minelayer : public Enemy
{

public :
	int difficulty;
	float spawnTimer = 0;
	float spawnFrequency = 0;

	Minelayer() = default;
	Minelayer(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Hitbox _hitbox, Texture2D _texture) :
		Enemy(_position, _speed, _scale, _spriteRect, _hitbox, _texture)
	{
		enablePhysics = true;
		spawnFrequency = difficulty / 10.0f;
	}
	~Minelayer() = default;
	void Update();

};