#include <raylib.h>
#include "../headers/Player.h"


// Debug
#include <string>

Player::Player(Vector2 _position, int _id, float _speed, float _scale, Rectangle _spriteRect, Texture2D _texture)
	: Entity(_position,_id, _speed, _scale, _spriteRect, _texture)
{
}

void Player::Update()
{
    if (IsKeyDown(KEY_W))
    {
        if (acceleration < 1) acceleration += 0.04f;
    }
    else
    {
        if (acceleration > 0) acceleration -= 0.02f;
        else if (acceleration < 0) acceleration = 0;
    }
     if (IsKeyDown(KEY_A))
    {
        rotation = -5;
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

    velocity.x = sin(rotation * DEG2RAD) * speed;
    velocity.y = cos(rotation * DEG2RAD) * speed;

    position.x += velocity.x * acceleration;
    position.y -= velocity.y * acceleration;
        
}
