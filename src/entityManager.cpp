#include "../headers/EntityManager.h"
#include "../headers/SpriteHelper.h"
#include "../headers/Player.h"
#include "../headers/Mine.h"
#include "../headers/SpawnPoint.h"
#include "../headers/Bullet.h"
#include "../headers/MineLayer.h"
#include <raylib.h>


EntityManager::EntityManager(Texture _spriteSheet) : spriteSheet(_spriteSheet)
{
	LoadEntitiesReferences();
}

void EntityManager::LoadEntitiesReferences()
{
	Vector2 defaultPosition;
	defaultPosition.x = 0;
	defaultPosition.y = 0;

	Rectangle playerSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 0);
	Player* player = new Player(defaultPosition,0, 10, 0.25, playerSpriteRect, spriteSheet);
	prefabs[0] = (Entity*)player;

	Rectangle spawnPointSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 1);
	SpawnPoint* spawnPoint = new SpawnPoint(defaultPosition,1, 10, 1, spawnPointSpriteRect, spriteSheet);
	prefabs[1] = (Entity*)spawnPoint;

	Rectangle MineLayerSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 2);
	MineLayer* mineLayer = new MineLayer(defaultPosition,2, 10, 1, MineLayerSpriteRect, spriteSheet);
	prefabs[2] = (Entity*)mineLayer;

	Rectangle bulletSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 3);
	Bullet* bullet = new Bullet(defaultPosition,3, 10, 1, bulletSpriteRect, spriteSheet);
	prefabs[3] = (Entity*)bullet;

	Rectangle floatingMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 4);
	Floating_Mine* floatingMine = new Floating_Mine(defaultPosition,4, 10, 1, floatingMineSpriteRect, spriteSheet);
	prefabs[4] = (Entity*)floatingMine;

	Rectangle fireballMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 5);
	Fireball_Mine* fireballMine = new Fireball_Mine(defaultPosition,5, 10, 1, fireballMineSpriteRect, spriteSheet);
	prefabs[5] = (Entity*)fireballMine;

	Rectangle magneticMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 6);
	Magnetic_Mine* magneticMine = new Magnetic_Mine(defaultPosition,6, 10, 1, magneticMineSpriteRect, spriteSheet);
	prefabs[6] = (Entity*)magneticMine;

	Rectangle magneticFireballMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 7);
	Magnetic_Fireball_Mine* magneticFireballMine = new Magnetic_Fireball_Mine(defaultPosition,7, 10, 1, magneticFireballMineSpriteRect, spriteSheet);
	prefabs[7] = (Entity*)magneticFireballMine;
}

void EntityManager::InstantiateEntity(EntityIndexes index, Vector2 position)
{
	int entityIndex = (int)index;

	Entity* newEntity = new Entity(*prefabs[entityIndex]);
	newEntity->position = position;

	loadedEntities.push_back(newEntity);
}

void EntityManager::InstantiateEntity(EntityIndexes index, Vector2 position, float rotation)
{
	int entityIndex = (int)index;

	Entity* newEntity = new Entity(*prefabs[entityIndex]);
	newEntity->position = position;
	newEntity->rotation = rotation;

	loadedEntities.push_back(newEntity);
}

void EntityManager::DestroyEntity(Entity entity) {}

void EntityManager::UpdateEntities() 
{
	for (Entity* i : loadedEntities)
	{
		switch (i->id)
		{
		case 0:
			((Player*)i)->Update();
			break;
		case 1: 
			((SpawnPoint*)i)->Update();
			break;
		case 2:
			((MineLayer*)i)->Update();
			break;
		case 3:
			((Bullet*)i)->Update();
			break;
		case 4:
			((Floating_Mine*)i)->Update();
			break;
		case 5:
			((Fireball_Mine*)i)->Update();
			break;
		case 6:
			((Magnetic_Mine*)i)->Update();
			break;
		case 7:
			((Magnetic_Fireball_Mine*)i)->Update();
			break;
		default:
			break;
		}
	}
} 

void EntityManager::DrawEntities()
{
	for (Entity* i : loadedEntities)
	{
		i->Draw();
	}
}