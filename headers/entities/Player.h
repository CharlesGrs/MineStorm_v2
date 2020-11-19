#pragma once
#include <raylib.h>
#include <list>
#include "../../headers/entities/Entity.h"

class Player : public Entity
{
public :
	float acceleration = 0;
	Vector2 velocity = {0,0};
	bool playerOne = true;
	std::list<Entity> bullets;
	int health = 3;
	Player() = default;
	Player(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture) :
		Entity(_position, _speed, _scale, _spriteRect, _texture) {}

	void Update() override ;
	void UpdatePosition();
	void GetInput();

	Entity* Clone();

};