#include "../../headers/entities/MineLayer.h"
#include "../../headers/entities/SpawnPoint.h"
#include "../../headers/gameplay/EntityManager.h"
#include "../../headers/helpers/Vector2Helper.h"
#include "../../headers/core/Game.h"


void Minelayer::Update()
{
	position.y -= speed;
	position.y -= speed;
	spawnTimer += GetFrameTime();
	if (spawnTimer > spawnFrequency)
	{
		Vector2 vRand = Vector2{ position.x + rand() % 1080, position.y };
		Game::entityManager()->InstantiateEntity(EntityType::SpawnPoint, Vector2Helper::Add(position, vRand));
	}

}
