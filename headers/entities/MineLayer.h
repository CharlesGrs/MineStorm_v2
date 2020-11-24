#pragma once
#include "Enemy.h"

class Minelayer : public Enemy
{

	int difficulty;
	float spawnTimer = 0;
	float spawnFrequency = 0;

	MineLayer();
	void Update();

};