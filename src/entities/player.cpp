#include <raylib.h>
#include <string>
#include "../../headers/entities/Player.h"
#include "../../headers/gameplay/World.h"
#include "../../headers/entities/Bullet.h"
#include "../../headers/helpers/Vector2Helper.h"

Entity* Player::Clone() {
	return new Player(*this);
}

void Player::UpdatePosition()
{
	position = Vector2Helper::Add(inertia, position);
}

void Player::GetInput()
{
	bool accelerate = false;
	if (IsKeyDown(KEY_W))
	{
		float magnitude = Vector2Helper::Magnitude(inertia);
		if (magnitude < speed)
		{
			Vector2 currentDirection = Vector2Helper::Multiply(Vector2Helper::AngleToVector2(rotation), 0.25f);
			inertia.y -= currentDirection.y;
			inertia.x += currentDirection.x;
			accelerate = true;
		}
	}
	if (!accelerate)
	{
		float factor = IsKeyDown(KEY_S) ? 2.5f : 0.7f;
		inertia = Vector2Helper::Lerp(inertia, Vector2{ 0,0 }, GetFrameTime() * factor);
	}

	if (IsKeyDown(KEY_A))
	{
		rotation -= 5;
		RotateHitbox(-5);
	}
	else if (IsKeyDown(KEY_D))
	{
		rotation += 5;
		RotateHitbox(5);
	}

	if (IsKeyDown(KEY_F))
	{
		bulletTimer += GetFrameTime();
		if (bulletTimer > SHOOTING_SPEED)
		{
			bulletTimer -= SHOOTING_SPEED;
			Shoot();
		}
	}
}

void Player::Update()
{
	Entity::Update();
	GetInput();
	UpdatePosition();
}

void Player::Shoot()
{
	Entity* bullet = World::entityManager()->InstantiateEntity(EntityType::Bullet, position);
	bullet->rotation = rotation;
}

void Player::RenderTrail() 
{

}
