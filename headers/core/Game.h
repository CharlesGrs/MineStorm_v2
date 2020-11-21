#pragma once
#include <raylib.h>
#include "../core/Scene.h"
#include "../gameplay/EntityManager.h"

class Game : public Scene
{
private:
	static EntityManager* _eM;

public:

	Game()= default;
	~Game();

	static EntityManager* entityManager()
	{
		if (_eM == NULL)
			_eM = new EntityManager();
		return _eM;
	}

	void Update();
	void Debug();

	void NewGame(bool twoPlayer);
	void InitNewLevel();
	void SaveScore();
	void ExitGame();
};