#include "..\..\headers\core\Game.h"
#include <string>

EntityManager* Game::_eM;

Game::~Game()
{
	delete _eM;
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
	if (IsKeyReleased(KEY_SPACE))
	{
		Vector2 playerPos;
		playerPos.x = (float)(rand() % 1080);
		playerPos.y = (float)(rand() % 720);
		entityManager()->InstantiateEntity(EntityType::Player, playerPos, 0);
	}

	int size = (int)entityManager()->entityAmount();
	std::string s = "Entity count: " + std::to_string(size);
	char const* pChar = s.c_str();
	DrawText(pChar, 5, 10, 12, WHITE);
}
