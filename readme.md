Rules of the game :

The player controls a spaceship and is able to fire towards enemies to destroy them.

If the player touch a enemy or is hit by an enemy bullet, he lose one of his 3 lives.


Controls :

PLAYER ONE :
● “D“ & “G“ : change the ship rotation (Rotate Player)
● “Z“ : make the Player accelerate (Toward the front of the ship)
● “F” : Shoot a bullet
● “E” ou “T”: Teleport the Player randomly 

PLAYER TWO :
1. “J“ et “L“ : change the ship rotation (Rotate Player)
1. “I“ :  make the Player accelerate (Toward the front of the ship)
1. “K” : Shoot a bullet
1. “U” ou “O” : Teleport the Player randomly 


● "SPACE" : Pause the game.

Additional controls in-game to display shaders and debug. (F1, F2)

Features :
	
	● Movement in accordance with the law of inertia
		(Player.cpp -> GetInput() for the inertia update)
	● Cells system to limit the Collision fct calls (third layer of collision before the AABB check)
		(Physics2D.h -> cellGrid && Physics2D.cpp cells related fct)

	● Clean unity-like engine with scenes and architectural similarities

	● Player ship trail 
		(Player.cpp : GetThrusterPos & RenderTrail)
	

