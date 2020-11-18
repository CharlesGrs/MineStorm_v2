#pragma once
#include <raylib.h>
#include <list>
#include "Entity.h"

class Player : Entity
{
public :
	float acceleration;
	Vector2 velocity;
	bool playerOne;
	std::list<Entity> bullets;
	int health = 3;
	Player() = default;
	Player(Vector2 _position, float _speed, float scale, Rectangle _spriteRect, Texture2D _texture);

	void Draw();

	void Update();


	/*
			player.position.x += (player.speed.x*player.acceleration);
			player.position.y -= (player.speed.y*player.acceleration);
	*/
	void UpdatePosition();

	void Shoot();

	/*
			-Rotate
			-Accelerate
			-call Shoot()
	*/
	void GetInput();

	void Die();

};