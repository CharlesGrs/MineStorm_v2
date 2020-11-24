#include "..\..\headers\core\Game.h"
#include <string>

EntityManager* Game::_eM;
Physics2D* Game::_physics2D;

Game::~Game()
{
	std::cout << "Unload Game..\n";
	delete _eM;
	delete _physics2D;
}

void Game::Update()
{
	Debug();
	physics2D()->Update();
	entityManager()->UpdateEntities();
	entityManager()->DrawEntities();

	if (enemyLeft == 0)
	{
		InitNewLevel();
		level++;
	}
}

void Game::NewGame(bool twoPlayer)
{
}

void Game::InitNewLevel()
{
	// prendre en compte level pour la difficulty
}

void Game::SaveScore()
{
}

void Game::ExitGame()
{
}

void Game::Debug()
{
	if (IsKeyDown(KEY_SPACE))
	{
		Vector2 playerPos;
		playerPos.x = (float)(rand() % 1080);
		playerPos.y = (float)(rand() % 720);
		entityManager()->InstantiateEntity(EntityType::Player, playerPos, 0);
	}


}
