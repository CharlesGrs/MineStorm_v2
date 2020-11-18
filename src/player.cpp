#include <raylib.h>
#include "../headers/Player.h"


// Debug
#include <string>

Player::Player(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: Entity(_position,_id, _speed, _scale, _spriteRect, _texture)
{
}
void Player::UpdatePosition()
{
    velocity.x = sin((double)rotation * DEG2RAD) * speed;
    velocity.y = cos((double)rotation * DEG2RAD) * speed;

    position.x += velocity.x * acceleration;
    position.y -= velocity.y * acceleration;
}
void Player::GetInput()
{
    if (IsKeyDown(KEY_W))
    {
        if (acceleration < 1) acceleration += 0.04f;
    }
    else
    {
        if (acceleration > 0) acceleration -= 0.01f;
        else if (acceleration < 0) acceleration = 0;
    }
    if (IsKeyDown(KEY_A))
    {
        rotation -= 5;
    }
    else if (IsKeyDown(KEY_D))
    {
        rotation += 5;
    }
    if (IsKeyDown(KEY_S))
    {
        if (acceleration > 0) acceleration -= 0.04f;
        else if (acceleration < 0) acceleration = 0;
    }
}
void Player::Update()
{
    Entity::Update();
    GetInput();
    UpdatePosition(); 
}
