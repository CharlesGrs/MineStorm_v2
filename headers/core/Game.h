#pragma once
#include <raylib.h>
#include "../core/Scene.h"
#include "../gameplay/EntityManager.h"
#include "../gameplay/Physics2D.h"

class Game : public Scene
{
private:
	static EntityManager* _eM;
	static Physics2D* _physics2D;
	int enemyLeft = 0;
	int score = 0;
	int level = 0;

public:

	Game() = default;
	~Game();

	static EntityManager* entityManager()
	{
		if (_eM == NULL)
			_eM = new EntityManager();
		return _eM;
	}

	static Physics2D* physics2D()
	{
		if (_physics2D == NULL)
			_physics2D = new Physics2D();
		return _physics2D;
	}

	void Update();
	void Debug();

	void NewGame(bool twoPlayer);
	void InitNewLevel();
	void SaveScore();
	void ExitGame();

};