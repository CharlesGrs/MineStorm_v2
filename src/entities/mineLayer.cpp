#include "..\..\headers\entities\MineLayer.h"

Minelayer::MineLayer()
{
	spawnFrequency = difficulty / 10.0f;
}

void Minelayer::Update()
{
	position.y -= speed;

}
