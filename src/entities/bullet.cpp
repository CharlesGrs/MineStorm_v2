#include <raylib.h>
#include <iostream>
#include "../../headers/entities/Bullet.h"
#include "../../headers/gameplay/World.h"



Entity* Bullet::Clone() {
    return new Bullet(*this);
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
        World::entityManager()->DestroyEntity(this);
}

void Bullet::Draw()
{
    Entity::Draw();
}