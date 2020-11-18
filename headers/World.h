#pragma once
#include "../headers/EntityManager.h"

class World
{
public :
	
	World();
	EntityManager entityManager;
	void Update();
};