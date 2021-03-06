#include <raylib.h>
#include <string>
#include "../../headers/entities/Player.h"
#include "../../headers/core/Game.h"
#include "../../headers/entities/Bullet.h"
#include "../../headers/helpers/Vector2Helper.h"
#include <iostream>
using namespace std;

Entity* Player::Clone() {
	Player* clone = new Player(*this);
	Polygon* s = dynamic_cast<Polygon*>(hitbox.shape);
	clone->hitbox.shape = new Polygon(s->vertices);
	return clone;
}

void Player::UpdatePosition()
{
	position = Vector2Helper::Add(inertia, position);
}

void Player::GetInput()
{
	bool accelerate = false;

	if (playerOne ? IsKeyDown(KEY_W) : IsKeyDown(KEY_I))
	{
		float magnitude = Vector2Helper::Norm(inertia);
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
		inertia = Vector2Helper::Lerp(inertia, Vector2{ 0,0 }, GetFrameTime() * 3.5f);
	}

	if (playerOne ? IsKeyDown(KEY_A) : IsKeyDown(KEY_J))
	{
		rotation -= 5;
		RotateHitbox(-5);
	}
	else if (playerOne ? IsKeyDown(KEY_D) : IsKeyDown(KEY_L))
	{
		rotation += 5;
		RotateHitbox(5);
	}

	if (playerOne ? IsKeyDown(KEY_S) : IsKeyDown(KEY_K))
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

	RenderTrail();
}

void Player::Shoot()
{
	Entity* bullet = Game::entityManager()->InstantiateEntity(EntityType::Bullet, position, rotation);
}

Vector2 Player::GetThrusterPos() {
	Vector2 dir = Vector2Helper::AngleToVector2(rotation);
	float offset = -15;
	Vector2 thrusterPos = Vector2{ dir.x * offset + position.x, position.y - dir.y * offset };
	return thrusterPos;
}

void Player::RenderTrail()
{
	Vector2 thrusterPos = GetThrusterPos();
	DrawCircle(thrusterPos.x, thrusterPos.y, abs(sin(GetTime() * 10)) * 7, WHITE);

	int size = 10;

	trailTimer += GetFrameTime();
	if (trailTimer > TRAIL_FREQUENCY)
	{
		trailTimer -= TRAIL_FREQUENCY;
		trailPoints[0] = thrusterPos;
		for (size_t i = size - 1; i > 0; i--)
		{
			trailPoints[i] = trailPoints[i - 1];
		}
	}

	for (size_t i = 0; i < size - 1; i++)
	{
		if (Vector2Helper::Distance(trailPoints[i], trailPoints[i + 1]) > 100)
			continue;
		float t = (10 - i) / 10.0f;
		Color trailColor;
		trailColor.r = SKYBLUE.r + t * (WHITE.r - SKYBLUE.r);
		trailColor.g = SKYBLUE.g + t * (WHITE.g - SKYBLUE.g);
		trailColor.b = SKYBLUE.b + t * (WHITE.b - SKYBLUE.b);
		trailColor.a = 255;
		DrawLineEx(trailPoints[i], trailPoints[i + 1], t * 10, trailColor);
	}
}
