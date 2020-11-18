#pragma once
#include <raylib.h>
#include "Entity.h"

class Player:Entity
{
	float acceleration;
	Vector2 velocity;
	bool playerOne;
	Entity bullet;
	int health = 3;

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