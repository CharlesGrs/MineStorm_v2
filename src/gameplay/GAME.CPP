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

	entityManager()->UpdateEntities();
	entityManager()->DrawEntities();
}

void Game::NewGame(bool twoPlayer)
{
}

void Game::InitNewLevel()
{
}

void Game::SaveScore()
{
}

void Game::ExitGame()
{


}

void Game::Debug()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		Vector2 playerPos;
		playerPos.x = (float)(rand() % 1080);
		playerPos.y = (float)(rand() % 720);
		entityManager()->InstantiateEntity(EntityType::Player, playerPos, 0);
	}


}
