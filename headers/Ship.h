#pragma once
#include <raylib.h>

class ships
{
public :

	Vector2 position;

	void fire() const;
	virtual void move();
};