#include <raylib.h>
#include <iostream>
#include "../../headers/entities/Bullet.h"
#include "../../headers/core/Game.h"

Entity* Bullet::Clone() {

	Bullet* clone = new Bullet(*this);
	Circle* s = dynamic_cast<Circle*>(hitbox.shape);
	clone->hitbox.shape = new Circle(s->radius, s->center);
	return clone;
}

void Bullet::UpdatePosition()
{
	velocity.x = sin((double)rotation * DEG2RAD) * speed;
	velocity.y = cos((double)rotation * DEG2RAD) * speed;

	position.x += velocity.x;
	position.y -= velocity.y;
}

void Bullet::Update()
{
	Entity::Update();
	UpdatePosition();

	timer -= GetFrameTime();
	if (timer < 0)
		Game::entityManager()->DestroyEntity(this);

}

void Bullet::Draw()
{
	Entity::Draw();
}