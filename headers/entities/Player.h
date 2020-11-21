#pragma once
#include <raylib.h>
#include <list>
#include "../../headers/entities/Entity.h"


class Player : public Entity
{
public :

	Player() = default;
	Player(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Polygon _hitbox,Texture2D _texture) :
		Entity(_position, _speed, _scale, _spriteRect, _hitbox, _texture) 
	{
		enablePhysics = true;
	}

	void Update() override ;
	Entity* Clone();

private:

	void UpdatePosition();
	void GetInput();
	void Shoot();
	void RenderTrail();
	Vector2 GetThrusterPos();

	bool playerOne = true;
	int health = 3;
	Vector2 inertia = { 0,0 };
	float bulletTimer =0;
	const float SHOOTING_SPEED = 0.1f;
	const float TRAIL_FREQUENCY = 0.0166f;
	float trailTimer = 0;
	Vector2 trailPoints[10];
};