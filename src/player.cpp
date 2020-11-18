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
        velocity = { 0,-1 };    // toward top
        rotation = 0;
    }
    else if (IsKeyDown(KEY_A))
    {
        velocity = { -1,0 };    // toward left
        rotation = -90;
    }
    else if (IsKeyDown(KEY_D))
    {
        velocity = { 1,0 };     // toward right
        rotation = 90;
    }
    else if (IsKeyDown(KEY_S))
    {
        velocity = { 0,1 };     // toward down
        rotation = 180;
    }

    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
        
}
