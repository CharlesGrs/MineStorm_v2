#pragma once
#include <raylib.h>
#include "../helpers/PolygonHelper.h"
#include "../gameplay/Cell.h"


enum class EntityType : int
{
	Player = 0,
	SpawnPoint = 1,
	MineLayer = 2,
	Bullet = 3,
	FloatingMine = 4,
	FireballMine = 5,
	MagneticMine = 6,
	MagneticFireballMine = 7
};

class Entity
{
public:

	Entity() = default;
	Entity(Vector2 _position, float _speed, float _scale, Rectangle _spriteRect, Polygon hitbox,Texture2D _texture);
	virtual ~Entity() = default;

	Vector2 position;
	float rotation = 0;
	float scale;
	float speed;
	Polygon hitbox;

	EntityType type = EntityType::Player;
	Cell* currentCell;
	bool enablePhysics = false;

	Vector2 origin;
	Rectangle spriteRect;
	Rectangle hitboxRect;
	Texture2D texture;

	virtual void Update();
	virtual Entity* Clone() = 0;
	void Draw();

	void RotateHitbox(float angle);

private :
	bool isColliding = false;
};