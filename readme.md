# MineStorm

Controls :

PLAYER ONE :
1. “D“ & “Q“ : change the ship rotation (Rotate Player)
1. “Z“ : makes the Player accelerates (Toward the front of the ship)
1. “S” : Shoot a bullet

#PLAYER TWO :
1. “J“ et “L“ : change the ship rotation (Rotate Player)
1. “I“ :  makes the Player accelerates (Toward the front of the ship)
1. “K” : Shoot a bullet

Additional controls in-game to display shaders and debug. (F1, F2)


## Entity System

## Collision System
* Three layers:
	* Grid system to split the physics system in cells for optimization
	* AABB Check
	* SAT Algorithm
● Movement in accordance with the law of inertia
	(Player.cpp -> GetInput() for the inertia update)
● Cells system to limit the collision fct calls (third layer of collision before the AABB check)
(Physics2D.h -> cellGrid && Physics2D.cpp cells related fct)

● Clean unity-like engine with scenes and architectural similarities

● Player ship trail 
	(Player.cpp : GetThrusterPos & RenderTrail)


