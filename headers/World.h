#pragma once
#include "EntityManager.h"

class World
{
public :
	
	World();
	EntityManager entityManager;
	void Update();
};