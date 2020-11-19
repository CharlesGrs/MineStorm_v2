#pragma once
#include <raylib.h>
#include <list>
#include "../../headers/entities/Entity.h"

class Player : Entity
{
public :
	float acceleration = 0;
	Vector2 velocity = {0,0};
	bool playerOne = true;
	std::list<Entity> bullets;
	int health = 3;
	Player() = default;
	Player(Vector2 _position, int _id, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);

	void Draw();
	void Update();
	void UpdatePosition();
	void Shoot();

	void GetInput();
	void Die();

};