#pragma once
#include <raylib.h>
#include "../../headers/entities/Entity.h"

class Bullet : public Entity
{
public :
	Vector2 velocity = {0,0};
	Bullet(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Hitbox _hitbox, Texture2D _texture)
		: Entity(_position, _speed, _scale, _spriteRect, _hitbox, _texture) 
	{
		enablePhysics = true;
	};
	~Bullet() = default;

	float timer = 3;

	void Update();
	void Draw();
	void UpdatePosition();

	Entity* Clone();

};