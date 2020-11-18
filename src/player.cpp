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
    if (IsKeyDown(KEY_B))
    {
        DrawText("PRESSED B", 100, 300, 20, LIGHTGRAY);
    }
}
